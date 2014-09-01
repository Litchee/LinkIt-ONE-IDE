#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wstrcat_t)(VMWSTR dst, const VMWSTR src);
_vm_wstrcat_t _vm_wstrcat = NULL;

VMINT vm_wstrcat(VMWSTR dst, const VMWSTR src)
{
    if (NULL == _vm_wstrcat)
        _vm_wstrcat = (_vm_wstrcat_t)vm_get_sym_entry("vm_wstrcat");

    if (NULL != _vm_wstrcat)
        return _vm_wstrcat(dst,src);

    return (VMINT )-1;
}
