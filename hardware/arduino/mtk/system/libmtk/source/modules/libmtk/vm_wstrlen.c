#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wstrlen_t)(VMWSTR s);
_vm_wstrlen_t _vm_wstrlen = NULL;

VMINT vm_wstrlen(VMWSTR s)
{
    if (NULL == _vm_wstrlen)
        _vm_wstrlen = (_vm_wstrlen_t)vm_get_sym_entry("vm_wstrlen");

    if (NULL != _vm_wstrlen)
        return _vm_wstrlen(s);

    return (VMINT )-1;
}
