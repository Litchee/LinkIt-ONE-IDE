#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void *(*_vm_malloc_t)(int size);
_vm_malloc_t _vm_malloc = NULL;

void *vm_malloc(int size)
{
    if (NULL == _vm_malloc)
        _vm_malloc = (_vm_malloc_t)vm_get_sym_entry("vm_malloc");

    if (NULL != _vm_malloc)
        return _vm_malloc(size);
	return NULL;

    
}
