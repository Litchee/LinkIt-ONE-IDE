#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_mixed_resume_t)(VMINT handle);
_vm_audio_mixed_resume_t _vm_audio_mixed_resume = NULL;

VMINT vm_audio_mixed_resume(VMINT handle)
{
    if (NULL == _vm_audio_mixed_resume)
        _vm_audio_mixed_resume = (_vm_audio_mixed_resume_t)vm_get_sym_entry("vm_audio_mixed_resume");

    if (NULL != _vm_audio_mixed_resume)
        return _vm_audio_mixed_resume(handle);
    return -1;
}
