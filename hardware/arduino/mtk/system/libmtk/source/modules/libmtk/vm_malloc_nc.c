#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void *(*_vm_malloc_nc_t)(int size);
_vm_malloc_nc_t _vm_malloc_nc = NULL;

void *vm_malloc_nc(int size)
{
    if (NULL == _vm_malloc_nc)
        _vm_malloc_nc = (_vm_malloc_nc_t)vm_get_sym_entry("vm_malloc_nc");

    if (NULL != _vm_malloc_nc)
        return _vm_malloc_nc(size);
    else 
        return NULL;
}
