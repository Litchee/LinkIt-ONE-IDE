#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wends_with_t)(const VMWSTR s1, const VMWSTR s2);
_vm_wends_with_t _vm_wends_with = NULL;

VMINT vm_wends_with(const VMWSTR s1, const VMWSTR s2)
{
    if (NULL == _vm_wends_with)
        _vm_wends_with = (_vm_wends_with_t)vm_get_sym_entry("vm_wends_with");

    if (NULL != _vm_wends_with)
        return _vm_wends_with(s1,s2);

    return (VMINT )-1;
}
