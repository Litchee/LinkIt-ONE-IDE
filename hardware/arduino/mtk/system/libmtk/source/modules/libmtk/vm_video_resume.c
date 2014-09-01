#include "vmsys.h"
#include "vmvideo.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_video_resume_t)(void);
_vm_video_resume_t _vm_video_resume = NULL;

VMINT vm_video_resume(void)
{
    if (NULL == _vm_video_resume)
        _vm_video_resume = (_vm_video_resume_t)vm_get_sym_entry("vm_video_resume");

    if (NULL != _vm_video_resume)
        return _vm_video_resume();

    return (VMINT )-1;
}
