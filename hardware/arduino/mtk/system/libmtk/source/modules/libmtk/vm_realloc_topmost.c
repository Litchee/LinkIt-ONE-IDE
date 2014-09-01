#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void *(*_vm_realloc_topmost_t)(void* p, int size);
_vm_realloc_topmost_t _vm_realloc_topmost = NULL;

void *vm_realloc_topmost(void* p, int size)
{
    if (NULL == _vm_realloc_topmost)
        _vm_realloc_topmost = (_vm_realloc_topmost_t)vm_get_sym_entry("vm_realloc_topmost");

    if (NULL != _vm_realloc_topmost)
       return _vm_realloc_topmost(p,size);
	return NULL;

    
}