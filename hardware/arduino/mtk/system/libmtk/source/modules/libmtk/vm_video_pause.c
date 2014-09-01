#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_pause_t)(void);
_vm_video_pause_t _vm_video_pause = NULL;

VMINT vm_video_pause(void)
{
    if (NULL == _vm_video_pause)
        _vm_video_pause = (_vm_video_pause_t)vm_get_sym_entry("vm_video_pause");

    if (NULL != _vm_video_pause)
        return _vm_video_pause();

    return (VMINT )-1;
}
