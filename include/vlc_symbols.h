/* DO NOT EDIT THIS FILE ! It was generated by bootstrap.sh */

struct module_symbols_t
{
    aout_fifo_t * (* __aout_CreateFifo_inner) ( vlc_object_t *, int, int, int, int, void * ) ;
    char * (* __config_GetPsz_inner) (vlc_object_t *, const char *) ;
    char * (* config_GetHomeDir_inner) ( void ) ;
    char * (* input_OffsetToTime_inner) ( input_thread_t *, char *, off_t ) ;
    char * (* mstrtime_inner) ( char *psz_buffer, mtime_t date ) ;
    const char * (* DecodeLanguage_inner) ( u16 ) ;
    const iso639_lang_t * (* GetLang_1_inner) ( const char * ) ;
    const iso639_lang_t * (* GetLang_2B_inner) ( const char * ) ;
    const iso639_lang_t * (* GetLang_2T_inner) ( const char * ) ;
    data_buffer_t * (* input_NewBuffer_inner) ( input_buffers_t *, size_t ) ;
    data_packet_t * (* input_NewPacket_inner) ( input_buffers_t *, size_t ) ;
    data_packet_t * (* input_ShareBuffer_inner) ( input_buffers_t *, data_buffer_t * ) ;
    es_descriptor_t * (* input_AddES_inner) ( input_thread_t *, pgrm_descriptor_t *, u16, size_t ) ;
    es_descriptor_t * (* input_FindES_inner) ( input_thread_t *, u16 ) ;
    es_descriptor_t * (* input_ParsePS_inner) ( input_thread_t *, data_packet_t * ) ;
    float (* __config_GetFloat_inner) (vlc_object_t *, const char *) ;
    input_area_t * (* input_AddArea_inner) ( input_thread_t * ) ;
    input_info_category_t * (* input_InfoCategory_inner) ( input_thread_t *, char * ) ;
    int (* __config_GetInt_inner) (vlc_object_t *, const char *) ;
    int (* __config_LoadCmdLine_inner) ( vlc_object_t *, int *, char *[], vlc_bool_t ) ;
    int (* __config_LoadConfigFile_inner) ( vlc_object_t *, const char * ) ;
    int (* __config_SaveConfigFile_inner) ( vlc_object_t *, const char * ) ;
    int (* __intf_Eject_inner) ( vlc_object_t *, const char * ) ;
    int (* __network_ChannelCreate_inner) ( vlc_object_t * ) ;
    int (* __network_ChannelJoin_inner) ( vlc_object_t *, int ) ;
    int (* __vlc_cond_destroy_inner) ( char *, int, vlc_cond_t * ) ;
    int (* __vlc_cond_init_inner) ( vlc_object_t *, vlc_cond_t * ) ;
    int (* __vlc_mutex_destroy_inner) ( char *, int, vlc_mutex_t * ) ;
    int (* __vlc_mutex_init_inner) ( vlc_object_t *, vlc_mutex_t * ) ;
    int (* __vlc_thread_create_inner) ( vlc_object_t *, char *, int, char *, void * ( * ) ( void * ), vlc_bool_t ) ;
    int (* __vlc_threads_end_inner) ( vlc_object_t * ) ;
    int (* __vlc_threads_init_inner) ( vlc_object_t * ) ;
    int (* input_AccessInit_inner) ( input_thread_t * ) ;
    int (* input_AddInfo_inner) ( input_info_category_t *, char *, char *, ... ) ;
    int (* input_ChangeArea_inner) ( input_thread_t *, input_area_t * ) ;
    int (* input_ChangeProgram_inner) ( input_thread_t *, u16 ) ;
    int (* input_ClockManageControl_inner) ( input_thread_t *, pgrm_descriptor_t *, mtime_t ) ;
    int (* input_InitStream_inner) ( input_thread_t *, size_t ) ;
    int (* input_SelectES_inner) ( input_thread_t *, es_descriptor_t * ) ;
    int (* input_SetProgram_inner) ( input_thread_t *, pgrm_descriptor_t * ) ;
    int (* input_ToggleES_inner) ( input_thread_t *, es_descriptor_t *, vlc_bool_t ) ;
    int (* input_UnselectES_inner) ( input_thread_t *, es_descriptor_t * ) ;
    int (* playlist_Add_inner) ( playlist_t *, const char *, int, int ) ;
    int (* playlist_Delete_inner) ( playlist_t *, int ) ;
    int (* vout_ChromaCmp_inner) ( u32, u32 ) ;
    intf_thread_t * (* __intf_Create_inner) ( vlc_object_t * ) ;
    module_config_t * (* config_FindConfig_inner) ( vlc_object_t *, const char *psz_name ) ;
    module_t * (* __module_Need_inner) ( vlc_object_t *, const char *, const char * ) ;
    msg_subscription_t* (* __msg_Subscribe_inner) ( vlc_object_t * ) ;
    mtime_t (* input_ClockGetTS_inner) ( input_thread_t *, pgrm_descriptor_t *, mtime_t ) ;
    mtime_t (* mdate_inner) ( void ) ;
    pes_packet_t * (* input_NewPES_inner) ( input_buffers_t * ) ;
    pgrm_descriptor_t * (* input_AddProgram_inner) ( input_thread_t *, u16, size_t ) ;
    pgrm_descriptor_t * (* input_FindProgram_inner) ( input_thread_t *, u16 ) ;
    picture_t * (* vout_CreatePicture_inner) ( vout_thread_t *, vlc_bool_t, vlc_bool_t, vlc_bool_t ) ;
    ssize_t (* input_FDNetworkRead_inner) ( input_thread_t *, byte_t *, size_t ) ;
    ssize_t (* input_FDRead_inner) ( input_thread_t *, byte_t *, size_t ) ;
    ssize_t (* input_FillBuffer_inner) ( input_thread_t * ) ;
    ssize_t (* input_Peek_inner) ( input_thread_t *, byte_t **, size_t ) ;
    ssize_t (* input_ReadPS_inner) ( input_thread_t *, data_packet_t ** ) ;
    ssize_t (* input_ReadTS_inner) ( input_thread_t *, data_packet_t ** ) ;
    ssize_t (* input_SplitBuffer_inner) ( input_thread_t *, data_packet_t **, size_t ) ;
    subpicture_t * (* vout_CreateSubPicture_inner) ( vout_thread_t *, int, int ) ;
    u32 (* UnalignedGetBits_inner) ( bit_stream_t *, unsigned int ) ;
    u32 (* UnalignedShowBits_inner) ( bit_stream_t *, unsigned int ) ;
    vlc_bool_t (* NextDataPacket_inner) ( decoder_fifo_t *, data_packet_t ** ) ;
    vlc_error_t (* intf_RunThread_inner) ( intf_thread_t * ) ;
    void (* BitstreamNextDataPacket_inner) ( bit_stream_t * ) ;
    void (* CurrentPTS_inner) ( bit_stream_t *, mtime_t *, mtime_t * ) ;
    void (* DecoderError_inner) ( decoder_fifo_t * p_fifo ) ;
    void (* InitBitstream_inner) ( bit_stream_t *, decoder_fifo_t *, void ( * )( bit_stream_t *, vlc_bool_t ), void * p_callback_arg ) ;
    void (* UnalignedRemoveBits_inner) ( bit_stream_t * ) ;
    void (* __config_PutFloat_inner) (vlc_object_t *, const char *, float) ;
    void (* __config_PutInt_inner) (vlc_object_t *, const char *, int) ;
    void (* __config_PutPsz_inner) (vlc_object_t *, const char *, const char *) ;
    void (* __input_FDClose_inner) ( vlc_object_t * ) ;
    void (* __input_FDNetworkClose_inner) ( vlc_object_t * ) ;
    void (* __input_Seek_inner) ( vlc_object_t *, off_t, int ) ;
    void (* __input_SetStatus_inner) ( vlc_object_t *, int ) ;
    void (* __input_Tell_inner) ( vlc_object_t *, stream_position_t * ) ;
    void (* __module_Unneed_inner) ( vlc_object_t *, module_t * ) ;
    void (* __msg_Dbg_inner) ( void *, const char *, ... ) ;
    void (* __msg_Err_inner) ( void *, const char *, ... ) ;
    void (* __msg_Generic_inner) ( vlc_object_t *, int, const char *, const char *, ... ) ;
    void (* __msg_Info_inner) ( void *, const char *, ... ) ;
    void (* __msg_Unsubscribe_inner) ( vlc_object_t *, msg_subscription_t * ) ;
    void (* __msg_Warn_inner) ( void *, const char *, ... ) ;
    void (* __vlc_dumpstructure_inner) ( vlc_object_t * ) ;
    void (* __vlc_object_attach_inner) ( vlc_object_t *, vlc_object_t * ) ;
    void (* __vlc_object_destroy_inner) ( vlc_object_t * ) ;
    void (* __vlc_object_detach_all_inner) ( vlc_object_t * ) ;
    void (* __vlc_object_detach_inner) ( vlc_object_t *, vlc_object_t * ) ;
    void (* __vlc_object_release_inner) ( vlc_object_t * ) ;
    void (* __vlc_object_yield_inner) ( vlc_object_t * ) ;
    void (* __vlc_thread_join_inner) ( vlc_object_t *, char *, int ) ;
    void (* __vlc_thread_ready_inner) ( vlc_object_t * ) ;
    void (* aout_DestroyFifo_inner) ( aout_fifo_t *p_fifo ) ;
    void (* config_Duplicate_inner) ( module_t *, module_config_t * ) ;
    void (* config_SetCallbacks_inner) ( module_config_t *, module_config_t * ) ;
    void (* config_UnsetCallbacks_inner) ( module_config_t * ) ;
    void (* input_AccessEnd_inner) ( input_thread_t * ) ;
    void (* input_AccessReinit_inner) ( input_thread_t * ) ;
    void (* input_BuffersEnd_inner) ( input_thread_t *, input_buffers_t * ) ;
    void (* input_ClockManageRef_inner) ( input_thread_t *, pgrm_descriptor_t *, mtime_t ) ;
    void (* input_DecodePES_inner) ( decoder_fifo_t *, pes_packet_t * ) ;
    void (* input_DelArea_inner) ( input_thread_t *, input_area_t * ) ;
    void (* input_DelES_inner) ( input_thread_t *, es_descriptor_t * ) ;
    void (* input_DelProgram_inner) ( input_thread_t *, pgrm_descriptor_t * ) ;
    void (* input_DeletePES_inner) ( input_buffers_t *, pes_packet_t * ) ;
    void (* input_DeletePacket_inner) ( input_buffers_t *, data_packet_t * ) ;
    void (* input_DemuxPS_inner) ( input_thread_t *, data_packet_t * ) ;
    void (* input_DemuxTS_inner) ( input_thread_t *, data_packet_t *, void(*) ( input_thread_t *, data_packet_t *, es_descriptor_t *, vlc_bool_t ) ) ;
    void (* input_DumpStream_inner) ( input_thread_t * ) ;
    void (* input_EndStream_inner) ( input_thread_t * ) ;
    void (* input_FDSeek_inner) ( input_thread_t *, off_t ) ;
    void (* input_GatherPES_inner) ( input_thread_t *, data_packet_t *, es_descriptor_t *, vlc_bool_t, vlc_bool_t ) ;
    void (* input_ParsePES_inner) ( input_thread_t *, es_descriptor_t * ) ;
    void (* input_ReleaseBuffer_inner) ( input_buffers_t *, data_buffer_t * ) ;
    void (* intf_Destroy_inner) ( intf_thread_t * ) ;
    void (* intf_StopThread_inner) ( intf_thread_t * ) ;
    void (* msleep_inner) ( mtime_t delay ) ;
    void (* mwait_inner) ( mtime_t date ) ;
    void (* playlist_Command_inner) ( playlist_t *, int, int ) ;
    void (* vout_AllocatePicture_inner) ( vout_thread_t *, picture_t *, int, int, u32 ) ;
    void (* vout_DatePicture_inner) ( vout_thread_t *, picture_t *, mtime_t ) ;
    void (* vout_DestroyPicture_inner) ( vout_thread_t *, picture_t * ) ;
    void (* vout_DestroySubPicture_inner) ( vout_thread_t *, subpicture_t * ) ;
    void (* vout_DestroyThread_inner) ( vout_thread_t * ) ;
    void (* vout_DisplayPicture_inner) ( vout_thread_t *, picture_t * ) ;
    void (* vout_DisplaySubPicture_inner) ( vout_thread_t *, subpicture_t * ) ;
    void (* vout_LinkPicture_inner) ( vout_thread_t *, picture_t * ) ;
    void (* vout_PlacePicture_inner) ( vout_thread_t *, int, int, int *, int *, int *, int * ) ;
    void (* vout_UnlinkPicture_inner) ( vout_thread_t *, picture_t * ) ;
    void * (* __vlc_object_create_inner) ( vlc_object_t *, int ) ;
    void * (* __vlc_object_find_inner) ( vlc_object_t *, int, int ) ;
    vout_thread_t * (* __vout_CreateThread_inner) ( vlc_object_t *, int, int, u32, int ) ;
};

#ifdef __PLUGIN__
#   define BitstreamNextDataPacket p_symbols->BitstreamNextDataPacket_inner
#   define CurrentPTS p_symbols->CurrentPTS_inner
#   define DecodeLanguage p_symbols->DecodeLanguage_inner
#   define DecoderError p_symbols->DecoderError_inner
#   define GetLang_1 p_symbols->GetLang_1_inner
#   define GetLang_2B p_symbols->GetLang_2B_inner
#   define GetLang_2T p_symbols->GetLang_2T_inner
#   define InitBitstream p_symbols->InitBitstream_inner
#   define NextDataPacket p_symbols->NextDataPacket_inner
#   define UnalignedGetBits p_symbols->UnalignedGetBits_inner
#   define UnalignedRemoveBits p_symbols->UnalignedRemoveBits_inner
#   define UnalignedShowBits p_symbols->UnalignedShowBits_inner
#   define __aout_CreateFifo p_symbols->__aout_CreateFifo_inner
#   define __config_GetFloat p_symbols->__config_GetFloat_inner
#   define __config_GetInt p_symbols->__config_GetInt_inner
#   define __config_GetPsz p_symbols->__config_GetPsz_inner
#   define __config_LoadCmdLine p_symbols->__config_LoadCmdLine_inner
#   define __config_LoadConfigFile p_symbols->__config_LoadConfigFile_inner
#   define __config_PutFloat p_symbols->__config_PutFloat_inner
#   define __config_PutInt p_symbols->__config_PutInt_inner
#   define __config_PutPsz p_symbols->__config_PutPsz_inner
#   define __config_SaveConfigFile p_symbols->__config_SaveConfigFile_inner
#   define __input_FDClose p_symbols->__input_FDClose_inner
#   define __input_FDNetworkClose p_symbols->__input_FDNetworkClose_inner
#   define __input_Seek p_symbols->__input_Seek_inner
#   define __input_SetStatus p_symbols->__input_SetStatus_inner
#   define __input_Tell p_symbols->__input_Tell_inner
#   define __intf_Create p_symbols->__intf_Create_inner
#   define __intf_Eject p_symbols->__intf_Eject_inner
#   define __module_Need p_symbols->__module_Need_inner
#   define __module_Unneed p_symbols->__module_Unneed_inner
#   define __msg_Dbg p_symbols->__msg_Dbg_inner
#   define __msg_Err p_symbols->__msg_Err_inner
#   define __msg_Generic p_symbols->__msg_Generic_inner
#   define __msg_Info p_symbols->__msg_Info_inner
#   define __msg_Subscribe p_symbols->__msg_Subscribe_inner
#   define __msg_Unsubscribe p_symbols->__msg_Unsubscribe_inner
#   define __msg_Warn p_symbols->__msg_Warn_inner
#   define __network_ChannelCreate p_symbols->__network_ChannelCreate_inner
#   define __network_ChannelJoin p_symbols->__network_ChannelJoin_inner
#   define __vlc_cond_destroy p_symbols->__vlc_cond_destroy_inner
#   define __vlc_cond_init p_symbols->__vlc_cond_init_inner
#   define __vlc_dumpstructure p_symbols->__vlc_dumpstructure_inner
#   define __vlc_mutex_destroy p_symbols->__vlc_mutex_destroy_inner
#   define __vlc_mutex_init p_symbols->__vlc_mutex_init_inner
#   define __vlc_object_attach p_symbols->__vlc_object_attach_inner
#   define __vlc_object_create p_symbols->__vlc_object_create_inner
#   define __vlc_object_destroy p_symbols->__vlc_object_destroy_inner
#   define __vlc_object_detach p_symbols->__vlc_object_detach_inner
#   define __vlc_object_detach_all p_symbols->__vlc_object_detach_all_inner
#   define __vlc_object_find p_symbols->__vlc_object_find_inner
#   define __vlc_object_release p_symbols->__vlc_object_release_inner
#   define __vlc_object_yield p_symbols->__vlc_object_yield_inner
#   define __vlc_thread_create p_symbols->__vlc_thread_create_inner
#   define __vlc_thread_join p_symbols->__vlc_thread_join_inner
#   define __vlc_thread_ready p_symbols->__vlc_thread_ready_inner
#   define __vlc_threads_end p_symbols->__vlc_threads_end_inner
#   define __vlc_threads_init p_symbols->__vlc_threads_init_inner
#   define __vout_CreateThread p_symbols->__vout_CreateThread_inner
#   define aout_DestroyFifo p_symbols->aout_DestroyFifo_inner
#   define config_Duplicate p_symbols->config_Duplicate_inner
#   define config_FindConfig p_symbols->config_FindConfig_inner
#   define config_GetHomeDir p_symbols->config_GetHomeDir_inner
#   define config_SetCallbacks p_symbols->config_SetCallbacks_inner
#   define config_UnsetCallbacks p_symbols->config_UnsetCallbacks_inner
#   define input_AccessEnd p_symbols->input_AccessEnd_inner
#   define input_AccessInit p_symbols->input_AccessInit_inner
#   define input_AccessReinit p_symbols->input_AccessReinit_inner
#   define input_AddArea p_symbols->input_AddArea_inner
#   define input_AddES p_symbols->input_AddES_inner
#   define input_AddInfo p_symbols->input_AddInfo_inner
#   define input_AddProgram p_symbols->input_AddProgram_inner
#   define input_BuffersEnd p_symbols->input_BuffersEnd_inner
#   define input_ChangeArea p_symbols->input_ChangeArea_inner
#   define input_ChangeProgram p_symbols->input_ChangeProgram_inner
#   define input_ClockGetTS p_symbols->input_ClockGetTS_inner
#   define input_ClockManageControl p_symbols->input_ClockManageControl_inner
#   define input_ClockManageRef p_symbols->input_ClockManageRef_inner
#   define input_DecodePES p_symbols->input_DecodePES_inner
#   define input_DelArea p_symbols->input_DelArea_inner
#   define input_DelES p_symbols->input_DelES_inner
#   define input_DelProgram p_symbols->input_DelProgram_inner
#   define input_DeletePES p_symbols->input_DeletePES_inner
#   define input_DeletePacket p_symbols->input_DeletePacket_inner
#   define input_DemuxPS p_symbols->input_DemuxPS_inner
#   define input_DemuxTS p_symbols->input_DemuxTS_inner
#   define input_DumpStream p_symbols->input_DumpStream_inner
#   define input_EndStream p_symbols->input_EndStream_inner
#   define input_FDNetworkRead p_symbols->input_FDNetworkRead_inner
#   define input_FDRead p_symbols->input_FDRead_inner
#   define input_FDSeek p_symbols->input_FDSeek_inner
#   define input_FillBuffer p_symbols->input_FillBuffer_inner
#   define input_FindES p_symbols->input_FindES_inner
#   define input_FindProgram p_symbols->input_FindProgram_inner
#   define input_GatherPES p_symbols->input_GatherPES_inner
#   define input_InfoCategory p_symbols->input_InfoCategory_inner
#   define input_InitStream p_symbols->input_InitStream_inner
#   define input_NewBuffer p_symbols->input_NewBuffer_inner
#   define input_NewPES p_symbols->input_NewPES_inner
#   define input_NewPacket p_symbols->input_NewPacket_inner
#   define input_OffsetToTime p_symbols->input_OffsetToTime_inner
#   define input_ParsePES p_symbols->input_ParsePES_inner
#   define input_ParsePS p_symbols->input_ParsePS_inner
#   define input_Peek p_symbols->input_Peek_inner
#   define input_ReadPS p_symbols->input_ReadPS_inner
#   define input_ReadTS p_symbols->input_ReadTS_inner
#   define input_ReleaseBuffer p_symbols->input_ReleaseBuffer_inner
#   define input_SelectES p_symbols->input_SelectES_inner
#   define input_SetProgram p_symbols->input_SetProgram_inner
#   define input_ShareBuffer p_symbols->input_ShareBuffer_inner
#   define input_SplitBuffer p_symbols->input_SplitBuffer_inner
#   define input_ToggleES p_symbols->input_ToggleES_inner
#   define input_UnselectES p_symbols->input_UnselectES_inner
#   define intf_Destroy p_symbols->intf_Destroy_inner
#   define intf_RunThread p_symbols->intf_RunThread_inner
#   define intf_StopThread p_symbols->intf_StopThread_inner
#   define mdate p_symbols->mdate_inner
#   define msleep p_symbols->msleep_inner
#   define mstrtime p_symbols->mstrtime_inner
#   define mwait p_symbols->mwait_inner
#   define playlist_Add p_symbols->playlist_Add_inner
#   define playlist_Command p_symbols->playlist_Command_inner
#   define playlist_Delete p_symbols->playlist_Delete_inner
#   define vout_AllocatePicture p_symbols->vout_AllocatePicture_inner
#   define vout_ChromaCmp p_symbols->vout_ChromaCmp_inner
#   define vout_CreatePicture p_symbols->vout_CreatePicture_inner
#   define vout_CreateSubPicture p_symbols->vout_CreateSubPicture_inner
#   define vout_DatePicture p_symbols->vout_DatePicture_inner
#   define vout_DestroyPicture p_symbols->vout_DestroyPicture_inner
#   define vout_DestroySubPicture p_symbols->vout_DestroySubPicture_inner
#   define vout_DestroyThread p_symbols->vout_DestroyThread_inner
#   define vout_DisplayPicture p_symbols->vout_DisplayPicture_inner
#   define vout_DisplaySubPicture p_symbols->vout_DisplaySubPicture_inner
#   define vout_LinkPicture p_symbols->vout_LinkPicture_inner
#   define vout_PlacePicture p_symbols->vout_PlacePicture_inner
#   define vout_UnlinkPicture p_symbols->vout_UnlinkPicture_inner
#endif /* __PLUGIN__ */

