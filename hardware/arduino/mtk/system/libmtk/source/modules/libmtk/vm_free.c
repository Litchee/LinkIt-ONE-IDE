#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_free_t)(void* ptr);
_vm_free_t _vm_free = NULL;

void vm_free(void* ptr)
{
    if (NULL == _vm_free)
        _vm_free = (_vm_free_t)vm_get_sym_entry("vm_free");

    if (NULL != _vm_free)
        _vm_free(ptr);

    
}
