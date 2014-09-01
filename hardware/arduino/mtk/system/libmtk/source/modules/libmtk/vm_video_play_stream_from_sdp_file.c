#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_play_stream_from_sdp_file_t)(VMWSTR filename, VMUCHAR is_short);
_vm_video_play_stream_from_sdp_file_t _vm_video_play_stream_from_sdp_file = NULL;

VMINT vm_video_play_stream_from_sdp_file(VMWSTR filename, VMUCHAR is_short)
{
    if (NULL == _vm_video_play_stream_from_sdp_file)
        _vm_video_play_stream_from_sdp_file = (_vm_video_play_stream_from_sdp_file_t)vm_get_sym_entry("vm_video_play_stream_from_sdp_file");

    if (NULL != _vm_video_play_stream_from_sdp_file)
        return _vm_video_play_stream_from_sdp_file(filename,is_short);

    return (VMINT )-1;
}
