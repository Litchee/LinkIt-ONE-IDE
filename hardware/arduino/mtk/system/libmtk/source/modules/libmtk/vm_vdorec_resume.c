#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_resume_t)(void);
_vm_vdorec_resume_t _vm_vdorec_resume = NULL;

VMINT vm_vdorec_resume(void)
{
    if (NULL == _vm_vdorec_resume)
        _vm_vdorec_resume = (_vm_vdorec_resume_t)vm_get_sym_entry("vm_vdorec_resume");

    if (NULL != _vm_vdorec_resume)
        return _vm_vdorec_resume();

    return (VMINT )-1;
}
