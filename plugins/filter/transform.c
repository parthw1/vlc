/*****************************************************************************
 * transform.c : transform image plugin for vlc
 *****************************************************************************
 * Copyright (C) 2000, 2001 VideoLAN
 * $Id: transform.c,v 1.17 2002/07/31 20:56:51 sam Exp $
 *
 * Authors: Samuel Hocevar <sam@zoy.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

/*****************************************************************************
 * Preamble
 *****************************************************************************/
#include <errno.h>
#include <stdlib.h>                                      /* malloc(), free() */
#include <string.h>

#include <vlc/vlc.h>
#include <vlc/vout.h>

#include "filter_common.h"

#define TRANSFORM_MODE_HFLIP   1
#define TRANSFORM_MODE_VFLIP   2
#define TRANSFORM_MODE_90      3
#define TRANSFORM_MODE_180     4
#define TRANSFORM_MODE_270     5

/*****************************************************************************
 * Local prototypes
 *****************************************************************************/
static int  Create    ( vlc_object_t * );
static void Destroy   ( vlc_object_t * );

static int  Init      ( vout_thread_t * );
static void End       ( vout_thread_t * );
static void Render    ( vout_thread_t *, picture_t * );

/*****************************************************************************
 * Module descriptor
 *****************************************************************************/
#define TYPE_TEXT N_("Transform type")
#define TYPE_LONGTEXT N_("One of '90', '180', '270', 'hflip' and 'vflip'")

static char *type_list[] = { "90", "180", "270", "hflip", "vflip", NULL };

vlc_module_begin();
    add_category_hint( N_("Miscellaneous"), NULL );
    add_string_from_list( "transform-type", "90", type_list, NULL,
                          TYPE_TEXT, TYPE_LONGTEXT);
    set_description( _("image transformation module") );
    set_capability( "video filter", 0 );
    add_shortcut( "transform" );
    set_callbacks( Create, Destroy );
vlc_module_end();

/*****************************************************************************
 * vout_sys_t: Transform video output method descriptor
 *****************************************************************************
 * This structure is part of the video output thread descriptor.
 * It describes the Transform specific properties of an output thread.
 *****************************************************************************/
struct vout_sys_t
{
    int i_mode;
    vlc_bool_t b_rotation;
    vout_thread_t *p_vout;
};

/*****************************************************************************
 * Create: allocates Transform video thread output method
 *****************************************************************************
 * This function allocates and initializes a Transform vout method.
 *****************************************************************************/
static int Create( vlc_object_t *p_this )
{
    vout_thread_t *p_vout = (vout_thread_t *)p_this;
    char *psz_method;

    /* Allocate structure */
    p_vout->p_sys = malloc( sizeof( vout_sys_t ) );
    if( p_vout->p_sys == NULL )
    {
        msg_Err( p_vout, "out of memory" );
        return( 1 );
    }

    p_vout->pf_init = Init;
    p_vout->pf_end = End;
    p_vout->pf_manage = NULL;
    p_vout->pf_render = Render;
    p_vout->pf_display = NULL;

    /* Look what method was requested */
    psz_method = config_GetPsz( p_vout, "transform-type" );

    if( psz_method == NULL )
    {
        msg_Err( p_vout, "configuration variable %s empty", "transform-type" );
        msg_Err( p_vout, "no valid transform mode provided, using '90'" );
        p_vout->p_sys->i_mode = TRANSFORM_MODE_90;
        p_vout->p_sys->b_rotation = 1;
    }
    else
    {
        if( !strcmp( psz_method, "hflip" ) )
        {
            p_vout->p_sys->i_mode = TRANSFORM_MODE_HFLIP;
            p_vout->p_sys->b_rotation = 0;
        }
        else if( !strcmp( psz_method, "vflip" ) )
        {
            p_vout->p_sys->i_mode = TRANSFORM_MODE_VFLIP;
            p_vout->p_sys->b_rotation = 0;
        }
        else if( !strcmp( psz_method, "90" ) )
        {
            p_vout->p_sys->i_mode = TRANSFORM_MODE_90;
            p_vout->p_sys->b_rotation = 1;
        }
        else if( !strcmp( psz_method, "180" ) )
        {
            p_vout->p_sys->i_mode = TRANSFORM_MODE_180;
            p_vout->p_sys->b_rotation = 0;
        }
        else if( !strcmp( psz_method, "270" ) )
        {
            p_vout->p_sys->i_mode = TRANSFORM_MODE_270;
            p_vout->p_sys->b_rotation = 1;
        }
        else
        {
            msg_Err( p_vout, "no valid transform mode provided, using '90'" );
            p_vout->p_sys->i_mode = TRANSFORM_MODE_90;
            p_vout->p_sys->b_rotation = 1;
        }

        free( psz_method );
    }
    
    return( 0 );
}

/*****************************************************************************
 * Init: initialize Transform video thread output method
 *****************************************************************************/
static int Init( vout_thread_t *p_vout )
{
    int i_index;
    picture_t *p_pic;
    
    I_OUTPUTPICTURES = 0;

    /* Initialize the output structure */
    p_vout->output.i_chroma = p_vout->render.i_chroma;
    p_vout->output.i_width  = p_vout->render.i_width;
    p_vout->output.i_height = p_vout->render.i_height;
    p_vout->output.i_aspect = p_vout->render.i_aspect;

    /* Try to open the real video output */
    msg_Dbg( p_vout, "spawning the real video output" );

    if( p_vout->p_sys->b_rotation )
    {
        p_vout->p_sys->p_vout =
            vout_CreateThread( p_vout,
                           p_vout->render.i_height, p_vout->render.i_width,
                           p_vout->render.i_chroma,
                           (u64)VOUT_ASPECT_FACTOR * (u64)VOUT_ASPECT_FACTOR
                               / (u64)p_vout->render.i_aspect );
    }
    else
    {
        p_vout->p_sys->p_vout =
            vout_CreateThread( p_vout,
                           p_vout->render.i_width, p_vout->render.i_height,
                           p_vout->render.i_chroma, p_vout->render.i_aspect );
    }

    /* Everything failed */
    if( p_vout->p_sys->p_vout == NULL )
    {
        msg_Err( p_vout, "cannot open vout, aborting" );
        return( 0 );
    }
 
    ALLOCATE_DIRECTBUFFERS( VOUT_MAX_PICTURES );

    return( 0 );
}

/*****************************************************************************
 * End: terminate Transform video thread output method
 *****************************************************************************/
static void End( vout_thread_t *p_vout )
{
    int i_index;

    /* Free the fake output buffers we allocated */
    for( i_index = I_OUTPUTPICTURES ; i_index ; )
    {
        i_index--;
        free( PP_OUTPUTPICTURE[ i_index ]->p_data_orig );
    }
}

/*****************************************************************************
 * Destroy: destroy Transform video thread output method
 *****************************************************************************
 * Terminate an output method created by TransformCreateOutputMethod
 *****************************************************************************/
static void Destroy( vlc_object_t *p_this )
{
    vout_thread_t *p_vout = (vout_thread_t *)p_this;

    vout_DestroyThread( p_vout->p_sys->p_vout );

    free( p_vout->p_sys );
}

/*****************************************************************************
 * Render: displays previously rendered output
 *****************************************************************************
 * This function send the currently rendered image to Transform image, waits
 * until it is displayed and switch the two rendering buffers, preparing next
 * frame.
 *****************************************************************************/
static void Render( vout_thread_t *p_vout, picture_t *p_pic )
{
    picture_t *p_outpic;
    int i_index;

    /* This is a new frame. Get a structure from the video_output. */
    while( ( p_outpic = vout_CreatePicture( p_vout->p_sys->p_vout, 0, 0, 0 ) )
              == NULL )
    {
        if( p_vout->b_die || p_vout->b_error )
        {
            return;
        }
        msleep( VOUT_OUTMEM_SLEEP );
    }   

    vout_DatePicture( p_vout->p_sys->p_vout, p_outpic, p_pic->date );
    vout_LinkPicture( p_vout->p_sys->p_vout, p_outpic );

    switch( p_vout->p_sys->i_mode )
    {
        case TRANSFORM_MODE_90:
            for( i_index = 0 ; i_index < p_pic->i_planes ; i_index++ )
            {
                int i_pitch = p_pic->p[i_index].i_pitch;

                u8 *p_in = p_pic->p[i_index].p_pixels;

                u8 *p_out = p_outpic->p[i_index].p_pixels;
                u8 *p_out_end = p_out + p_outpic->p[i_index].i_lines
                                         * p_outpic->p[i_index].i_pitch;

                for( ; p_out < p_out_end ; )
                {
                    u8 *p_line_end;

                    p_line_end = p_in + p_pic->p[i_index].i_lines
                                         * p_pic->p[i_index].i_pitch;

                    for( ; p_in < p_line_end ; )
                    {
                        p_line_end -= i_pitch;
                        *(--p_out_end) = *p_line_end;
                    }

                    p_in++;
                }
            }
            break;

        case TRANSFORM_MODE_180:
            for( i_index = 0 ; i_index < p_pic->i_planes ; i_index++ )
            {
                u8 *p_in = p_pic->p[i_index].p_pixels;
                u8 *p_in_end = p_in + p_pic->p[i_index].i_lines
                                       * p_pic->p[i_index].i_pitch;

                u8 *p_out = p_outpic->p[i_index].p_pixels;

                for( ; p_in < p_in_end ; )
                {
                    *p_out++ = *(--p_in_end);
                }
            }
            break;

        case TRANSFORM_MODE_270:
            for( i_index = 0 ; i_index < p_pic->i_planes ; i_index++ )
            {
                int i_pitch = p_pic->p[i_index].i_pitch;

                u8 *p_in = p_pic->p[i_index].p_pixels;

                u8 *p_out = p_outpic->p[i_index].p_pixels;
                u8 *p_out_end = p_out + p_outpic->p[i_index].i_lines
                                         * p_outpic->p[i_index].i_pitch;

                for( ; p_out < p_out_end ; )
                {
                    u8 *p_in_end;

                    p_in_end = p_in + p_pic->p[i_index].i_lines
                                       * p_pic->p[i_index].i_pitch;

                    for( ; p_in < p_in_end ; )
                    {
                        p_in_end -= i_pitch;
                        *p_out++ = *p_in_end;
                    }

                    p_in++;
                }
            }
            break;

        case TRANSFORM_MODE_VFLIP:
            for( i_index = 0 ; i_index < p_pic->i_planes ; i_index++ )
            {
                u8 *p_in = p_pic->p[i_index].p_pixels;
                u8 *p_in_end = p_in + p_pic->p[i_index].i_lines
                                       * p_pic->p[i_index].i_pitch;

                u8 *p_out = p_outpic->p[i_index].p_pixels;

                for( ; p_in < p_in_end ; )
                {
                    p_in_end -= p_pic->p[i_index].i_pitch;
                    p_vout->p_vlc->pf_memcpy( p_out, p_in_end,
                                              p_pic->p[i_index].i_pitch );
                    p_out += p_pic->p[i_index].i_pitch;
                }
            }
            break;

        case TRANSFORM_MODE_HFLIP:
            for( i_index = 0 ; i_index < p_pic->i_planes ; i_index++ )
            {
                u8 *p_in = p_pic->p[i_index].p_pixels;
                u8 *p_in_end = p_in + p_pic->p[i_index].i_lines
                                       * p_pic->p[i_index].i_pitch;

                u8 *p_out = p_outpic->p[i_index].p_pixels;

                for( ; p_in < p_in_end ; )
                {
                    u8 *p_line_end = p_in + p_pic->p[i_index].i_pitch;

                    for( ; p_in < p_line_end ; )
                    {
                        *p_out++ = *(--p_line_end);
                    }

                    p_in += p_pic->p[i_index].i_pitch;
                }
            }
            break;

        default:
            break;
    }

    vout_UnlinkPicture( p_vout->p_sys->p_vout, p_outpic );

    vout_DisplayPicture( p_vout->p_sys->p_vout, p_outpic );
}

