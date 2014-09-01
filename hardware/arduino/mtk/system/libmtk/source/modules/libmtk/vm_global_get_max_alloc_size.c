#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_global_get_max_alloc_size_t)(void);
_vm_global_get_max_alloc_size_t _vm_global_get_max_alloc_size = NULL;

VMINT vm_global_get_max_alloc_size(void)
{
    if (NULL == _vm_global_get_max_alloc_size)
        _vm_global_get_max_alloc_size = (_vm_global_get_max_alloc_size_t)vm_get_sym_entry("vm_global_get_max_alloc_size");

    if (NULL != _vm_global_get_max_alloc_size)
        return _vm_global_get_max_alloc_size();

    return (VMINT )-1;
}
