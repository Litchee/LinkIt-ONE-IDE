#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_midi_resume_t)(VMINT handle);
_vm_midi_resume_t _vm_midi_resume = NULL;

VMINT vm_midi_resume(VMINT handle)
{
    if (NULL == _vm_midi_resume)
        _vm_midi_resume = (_vm_midi_resume_t)vm_get_sym_entry("vm_midi_resume");

    if (NULL != _vm_midi_resume)
        return _vm_midi_resume(handle);

    return (VMINT )-1;
}
