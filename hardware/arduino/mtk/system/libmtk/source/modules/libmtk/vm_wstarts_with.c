#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wstarts_with_t)(VMWSTR a, VMWSTR b);
_vm_wstarts_with_t _vm_wstarts_with = NULL;

VMINT vm_wstarts_with(VMWSTR a, VMWSTR b)
{
    if (NULL == _vm_wstarts_with)
        _vm_wstarts_with = (_vm_wstarts_with_t)vm_get_sym_entry("vm_wstarts_with");

    if (NULL != _vm_wstarts_with)
        return _vm_wstarts_with(a,b);

    return (VMINT )-1;
}
