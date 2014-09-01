#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_play_t)( VMUINT player_layer_handle, VMUINT base_layer_handle, VMUINT16 repeat_count, VMINT is_play_audio, VMINT audio_path, vm_video_finish_callback play_finish_callback);
_vm_video_play_t _vm_video_play = NULL;

VMINT vm_video_play( VMUINT player_layer_handle, VMUINT base_layer_handle, VMUINT16 repeat_count, VMINT is_play_audio, VMINT audio_path, vm_video_finish_callback play_finish_callback)
{
    if (NULL == _vm_video_play)
        _vm_video_play = (_vm_video_play_t)vm_get_sym_entry("vm_video_play");

    if (NULL != _vm_video_play)
        return _vm_video_play(player_layer_handle,base_layer_handle,repeat_count,is_play_audio,audio_path,play_finish_callback);

    return (VMINT )-1;
}
