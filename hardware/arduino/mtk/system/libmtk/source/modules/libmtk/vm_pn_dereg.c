#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_dereg_t)();
_vm_pn_dereg_t _vm_pn_dereg = NULL;

VMINT vm_pn_dereg()
{
    if (NULL == _vm_pn_dereg)
        _vm_pn_dereg = (_vm_pn_dereg_t)vm_get_sym_entry("vm_pn_dereg");

    if (NULL != _vm_pn_dereg)
        return _vm_pn_dereg();

    return (VMINT)-1;
}