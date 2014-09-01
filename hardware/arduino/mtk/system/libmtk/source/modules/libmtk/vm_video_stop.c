#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_stop_t)(void);
_vm_video_stop_t _vm_video_stop = NULL;

VMINT vm_video_stop(void)
{
    if (NULL == _vm_video_stop)
        _vm_video_stop = (_vm_video_stop_t)vm_get_sym_entry("vm_video_stop");

    if (NULL != _vm_video_stop)
        return _vm_video_stop();

    return (VMINT )-1;
}
