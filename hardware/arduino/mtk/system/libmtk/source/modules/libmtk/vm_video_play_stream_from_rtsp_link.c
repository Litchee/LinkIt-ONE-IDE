#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_play_stream_from_rtsp_link_t)(VMWSTR url);
_vm_video_play_stream_from_rtsp_link_t _vm_video_play_stream_from_rtsp_link = NULL;

VMINT vm_video_play_stream_from_rtsp_link(VMWSTR url)
{
    if (NULL == _vm_video_play_stream_from_rtsp_link)
        _vm_video_play_stream_from_rtsp_link = (_vm_video_play_stream_from_rtsp_link_t)vm_get_sym_entry("vm_video_play_stream_from_rtsp_link");

    if (NULL != _vm_video_play_stream_from_rtsp_link)
        return _vm_video_play_stream_from_rtsp_link(url);

    return (VMINT )-1;
}
