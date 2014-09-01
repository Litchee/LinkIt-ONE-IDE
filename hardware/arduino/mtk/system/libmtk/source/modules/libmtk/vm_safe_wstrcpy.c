#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_safe_wstrcpy_t)(VMWSTR dest, VMINT size, VMWSTR src);
_vm_safe_wstrcpy_t _vm_safe_wstrcpy = NULL;

VMINT vm_safe_wstrcpy(VMWSTR dest, VMINT size, VMWSTR src)
{
    if (NULL == _vm_safe_wstrcpy)
        _vm_safe_wstrcpy = (_vm_safe_wstrcpy_t)vm_get_sym_entry("vm_safe_wstrcpy");

    if (NULL != _vm_safe_wstrcpy)
        return _vm_safe_wstrcpy(dest,size,src);

    return (VMINT )-1;
}
