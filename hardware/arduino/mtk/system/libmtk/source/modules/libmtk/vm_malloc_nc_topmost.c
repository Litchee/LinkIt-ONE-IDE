#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void *(*_vm_malloc_nc_topmost_t)(int size);
_vm_malloc_nc_topmost_t _vm_malloc_nc_topmost = NULL;

void *vm_malloc_nc_topmost(int size)
{
    if (NULL == _vm_malloc_nc_topmost)
        _vm_malloc_nc_topmost = (_vm_malloc_nc_topmost_t)vm_get_sym_entry("vm_malloc_nc_topmost");

    if (NULL != _vm_malloc_nc_topmost)
        return _vm_malloc_nc_topmost(size);
    else 
        return NULL;
}
