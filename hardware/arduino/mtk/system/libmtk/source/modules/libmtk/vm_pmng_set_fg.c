#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef  VM_P_HANDLE (*_vm_pmng_set_fg_t)(VMWSTR fileName);
_vm_pmng_set_fg_t _vm_pmng_set_fg = NULL;

VM_P_HANDLE vm_pmng_set_fg(VMWSTR fileName)
{
    if (NULL == _vm_pmng_set_fg)
        _vm_pmng_set_fg = (_vm_pmng_set_fg_t)vm_get_sym_entry("vm_pmng_set_fg");

    if (NULL != _vm_pmng_set_fg)
        return _vm_pmng_set_fg(fileName);
    else 
        return (VM_P_HANDLE)VM_PMNG_NO_SCHEDULE;
}
