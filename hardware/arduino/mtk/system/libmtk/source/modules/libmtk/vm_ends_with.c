#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ends_with_t)(const char *s1, const char *s2);
_vm_ends_with_t _vm_ends_with = NULL;

VMINT vm_ends_with(const char *s1, const char *s2)
{
    if (NULL == _vm_ends_with)
        _vm_ends_with = (_vm_ends_with_t)vm_get_sym_entry("vm_ends_with");

    if (NULL != _vm_ends_with)
        return _vm_ends_with(s1,s2);

    return (VMINT )-1;
}
