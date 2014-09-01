#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void *(*_vm_calloc_t)(int size);
_vm_calloc_t _vm_calloc = NULL;

void *vm_calloc(int size)
{
    if (NULL == _vm_calloc)
        _vm_calloc = (_vm_calloc_t)vm_get_sym_entry("vm_calloc");

    if (NULL != _vm_calloc)
        return _vm_calloc(size);
    return NULL;

    
}
