#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_find_first_t)(VMWSTR pathname, struct vm_fileinfo_t* info);
_vm_find_first_t _vm_find_first = NULL;

VMINT vm_find_first(VMWSTR pathname, struct vm_fileinfo_t* info)
{
    if (NULL == _vm_find_first)
        _vm_find_first = (_vm_find_first_t)vm_get_sym_entry("vm_find_first");

    if (NULL != _vm_find_first)
        return _vm_find_first(pathname,info);

    return (VMINT )-1;
}
