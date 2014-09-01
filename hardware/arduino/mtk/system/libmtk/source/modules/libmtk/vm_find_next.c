#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_find_next_t)(VMINT handle, struct vm_fileinfo_t* info);
_vm_find_next_t _vm_find_next = NULL;

VMINT vm_find_next(VMINT handle, struct vm_fileinfo_t* info)
{
    if (NULL == _vm_find_next)
        _vm_find_next = (_vm_find_next_t)vm_get_sym_entry("vm_find_next");

    if (NULL != _vm_find_next)
        return _vm_find_next(handle,info);

    return (VMINT )-1;
}
