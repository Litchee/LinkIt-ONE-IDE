#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_get_cur_play_time_t)(VMUINT64 *cur_play_time);
_vm_video_get_cur_play_time_t _vm_video_get_cur_play_time = NULL;

VMINT vm_video_get_cur_play_time(VMUINT64 *cur_play_time)
{
    if (NULL == _vm_video_get_cur_play_time)
        _vm_video_get_cur_play_time = (_vm_video_get_cur_play_time_t)vm_get_sym_entry("vm_video_get_cur_play_time");

    if (NULL != _vm_video_get_cur_play_time)
        return _vm_video_get_cur_play_time(cur_play_time);

    return (VMINT )-1;
}
