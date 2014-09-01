#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wstrncpy_t)(VMWSTR dst, const VMWSTR src, VMINT length);
_vm_wstrncpy_t _vm_wstrncpy = NULL;

VMINT vm_wstrncpy(VMWSTR dst, const VMWSTR src, VMINT length)
{
    if (NULL == _vm_wstrncpy)
        _vm_wstrncpy = (_vm_wstrncpy_t)vm_get_sym_entry("vm_wstrncpy");

    if (NULL != _vm_wstrncpy)
        return _vm_wstrncpy(dst,src,length);

    return (VMINT )-1;
}
