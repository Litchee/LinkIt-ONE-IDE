#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void *(*_vm_global_malloc_t)(unsigned int size);
_vm_global_malloc_t _vm_global_malloc = NULL;

void *vm_global_malloc(unsigned int size)
{
    if (NULL == _vm_global_malloc)
        _vm_global_malloc = (_vm_global_malloc_t)vm_get_sym_entry("vm_global_malloc");

    if (NULL != _vm_global_malloc)
        return _vm_global_malloc(size);

    return NULL;
}
