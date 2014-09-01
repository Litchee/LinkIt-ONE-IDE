#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wstrcpy_t)(VMWSTR dst, const VMWSTR src);
_vm_wstrcpy_t _vm_wstrcpy = NULL;

VMINT vm_wstrcpy(VMWSTR dst, const VMWSTR src)
{
    if (NULL == _vm_wstrcpy)
        _vm_wstrcpy = (_vm_wstrcpy_t)vm_get_sym_entry("vm_wstrcpy");

    if (NULL != _vm_wstrcpy)
        return _vm_wstrcpy(dst,src);

    return (VMINT )-1;
}
