#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_close_buffer_t)(void);
_vm_video_close_buffer_t _vm_video_close_buffer = NULL;

VMINT vm_video_close_buffer(void)
{
    if (NULL == _vm_video_close_buffer)
        _vm_video_close_buffer = (_vm_video_close_buffer_t)vm_get_sym_entry("vm_video_close_buffer");

    if (NULL != _vm_video_close_buffer)
        return _vm_video_close_buffer();

    return (VMINT )-1;
}
