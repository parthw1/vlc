/*****************************************************************************
 * aout_dummy.c : dummy audio output plugin
 *****************************************************************************
 * Copyright (C) 2000, 2001 VideoLAN
 * $Id: aout_dummy.c,v 1.23 2002/07/31 20:56:51 sam Exp $
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
#include <string.h>

#include <vlc/vlc.h>
#include <vlc/aout.h>

/*****************************************************************************
 * Local prototypes.
 *****************************************************************************/
static int     SetFormat   ( aout_thread_t * );
static int     GetBufInfo  ( aout_thread_t *, int );
static void    Play        ( aout_thread_t *, byte_t *, int );

/*****************************************************************************
 * OpenAudio: opens a dummy audio device
 *****************************************************************************/
int E_(OpenAudio) ( vlc_object_t *p_this )
{
    aout_thread_t * p_aout = (aout_thread_t *)p_this;

    p_aout->pf_setformat = SetFormat;
    p_aout->pf_getbufinfo = GetBufInfo;
    p_aout->pf_play = Play;

    return VLC_SUCCESS;
}

/*****************************************************************************
 * SetFormat: pretends to set the dsp output format
 *****************************************************************************/
static int SetFormat( aout_thread_t *p_aout )
{
    return( 0 );
}

/*****************************************************************************
 * GetBufInfo: returns available bytes in buffer
 *****************************************************************************/
static int GetBufInfo( aout_thread_t *p_aout, int i_buffer_limit )
{
    return( sizeof(s16) * i_buffer_limit + 1 ); /* value big enough to sleep */
}

/*****************************************************************************
 * Play: pretends to play a sound
 *****************************************************************************/
static void Play( aout_thread_t *p_aout, byte_t *buffer, int i_size )
{
    ;
}

