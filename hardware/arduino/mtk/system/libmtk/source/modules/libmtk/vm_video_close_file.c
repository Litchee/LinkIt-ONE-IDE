#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_close_file_t)(void);
_vm_video_close_file_t _vm_video_close_file = NULL;

VMINT vm_video_close_file(void)
{
    if (NULL == _vm_video_close_file)
        _vm_video_close_file = (_vm_video_close_file_t)vm_get_sym_entry("vm_video_close_file");

    if (NULL != _vm_video_close_file)
        return _vm_video_close_file();

    return (VMINT )-1;
}
