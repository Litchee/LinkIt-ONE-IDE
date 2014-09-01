#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_seek_and_getframe_t)(VMUINT64 time, VMUINT player_layer_handle);
_vm_video_seek_and_getframe_t _vm_video_seek_and_getframe = NULL;

VMINT vm_video_seek_and_getframe(VMUINT64 time, VMUINT player_layer_handle)
{
    if (NULL == _vm_video_seek_and_getframe)
        _vm_video_seek_and_getframe = (_vm_video_seek_and_getframe_t)vm_get_sym_entry("vm_video_seek_and_getframe");

    if (NULL != _vm_video_seek_and_getframe)
        return _vm_video_seek_and_getframe(time,player_layer_handle);

    return (VMINT )-1;
}
