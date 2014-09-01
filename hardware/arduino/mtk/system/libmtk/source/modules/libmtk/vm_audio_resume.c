#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_resume_t)(void (*f)(VMINT result));
_vm_audio_resume_t _vm_audio_resume = NULL;

VMINT vm_audio_resume(void (*f)(VMINT result))
{
    if (NULL == _vm_audio_resume)
        _vm_audio_resume = (_vm_audio_resume_t)vm_get_sym_entry("vm_audio_resume");

    if (NULL != _vm_audio_resume)
        return _vm_audio_resume(f);

    return (VMINT )-1;
}
