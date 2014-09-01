#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_snapshot_t)(VMUINT player_layer_handle, VMWSTR file_name);
_vm_video_snapshot_t _vm_video_snapshot = NULL;

VMINT vm_video_snapshot(VMUINT player_layer_handle, VMWSTR file_name)
{
    if (NULL == _vm_video_snapshot)
        _vm_video_snapshot = (_vm_video_snapshot_t)vm_get_sym_entry("vm_video_snapshot");

    if (NULL != _vm_video_snapshot)
        return _vm_video_snapshot(player_layer_handle,file_name);

    return (VMINT )-1;
}
