#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void *(*_vm_realloc_t)(void* p, int size);
_vm_realloc_t _vm_realloc = NULL;

void *vm_realloc(void* p, int size)
{
    if (NULL == _vm_realloc)
        _vm_realloc = (_vm_realloc_t)vm_get_sym_entry("vm_realloc");

    if (NULL != _vm_realloc)
       return _vm_realloc(p,size);
	return NULL;

    
}
