/*****************************************************************************
 * file.c: file input (file: access plug-in)
 *****************************************************************************
 * Copyright (C) 2001, 2002 VideoLAN
 * $Id: file.c,v 1.8 2002/07/31 20:56:50 sam Exp $
 *
 * Authors: Christophe Massiot <massiot@via.ecp.fr>
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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include <vlc/vlc.h>
#include <vlc/input.h>

#ifdef HAVE_UNISTD_H
#   include <unistd.h>
#elif defined( _MSC_VER ) && defined( _WIN32 )
#   include <io.h>
#endif

/*****************************************************************************
 * Open: open the file
 *****************************************************************************/
static int Open( vlc_object_t *p_this )
{
    input_thread_t *    p_input = (input_thread_t *)p_this;
    char *              psz_name = p_input->psz_name;
    int                 i_stat;
    struct stat         stat_info;                                              
    input_socket_t *    p_access_data;
    vlc_bool_t          b_stdin;

    p_input->i_mtu = 0;

    b_stdin = psz_name[0] == '-' && psz_name[1] == '\0';

    if( !b_stdin && (i_stat = stat( psz_name, &stat_info )) == (-1) )
    {
        msg_Err( p_input, "cannot stat() file `%s' (%s)",
                          psz_name, strerror(errno));
        return( -1 );
    }

    p_input->pf_read = input_FDRead;
    p_input->pf_set_program = input_SetProgram;
    p_input->pf_set_area = NULL;
    p_input->pf_seek = input_FDSeek;

    vlc_mutex_lock( &p_input->stream.stream_lock );

    if( *p_input->psz_access && !strncmp( p_input->psz_access, "stream", 7 ) )
    {
        /* stream:%s */
        p_input->stream.b_pace_control = 0;
        p_input->stream.b_seekable = 0;
        p_input->stream.p_selected_area->i_size = 0;
    }
    else
    {
        /* file:%s or %s */
        p_input->stream.b_pace_control = 1;

        if( b_stdin )
        {
            p_input->stream.b_seekable = 0;
            p_input->stream.p_selected_area->i_size = 0;
        }
        else if( S_ISREG(stat_info.st_mode) || S_ISCHR(stat_info.st_mode)
                  || S_ISBLK(stat_info.st_mode) )
        {
            p_input->stream.b_seekable = 1;
            p_input->stream.p_selected_area->i_size = stat_info.st_size;
        }
        else if( S_ISFIFO(stat_info.st_mode)
#if !defined( SYS_BEOS ) && !defined( WIN32 )
                  || S_ISSOCK(stat_info.st_mode)
#endif
               )
        {
            p_input->stream.b_seekable = 0;
            p_input->stream.p_selected_area->i_size = 0;
        }
        else
        {
            vlc_mutex_unlock( &p_input->stream.stream_lock );
            msg_Err( p_input, "unknown file type for `%s'", psz_name );
            return( -1 );
        }
    }
 
    p_input->stream.p_selected_area->i_tell = 0;
    p_input->stream.i_method = INPUT_METHOD_FILE;
    vlc_mutex_unlock( &p_input->stream.stream_lock );
 
    msg_Dbg( p_input, "opening file `%s'", psz_name );
    p_access_data = malloc( sizeof(input_socket_t) );
    p_input->p_access_data = (void *)p_access_data;
    if( p_access_data == NULL )
    {
        msg_Err( p_input, "out of memory" );
        return( -1 );
    }

    if( b_stdin )
    {
        p_access_data->i_handle = 0;
    }
    else if( (p_access_data->i_handle = open( psz_name,
                                   /*O_NONBLOCK | O_LARGEFILE*/ 0 )) == (-1) )
    {
        msg_Err( p_input, "cannot open file %s (%s)", psz_name,
                          strerror(errno) );
        free( p_access_data );
        return( -1 );
    }

    return( 0 );
}

/*****************************************************************************
 * Module descriptor
 *****************************************************************************/
vlc_module_begin();
    set_description( _("Standard filesystem file reading") );
    set_capability( "access", 50 );
    add_shortcut( "stream" );
    set_callbacks( Open, __input_FDClose );
vlc_module_end();
 
