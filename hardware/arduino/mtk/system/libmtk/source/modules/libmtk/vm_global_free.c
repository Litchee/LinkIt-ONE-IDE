#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_global_free_t)(void* ptr);
_vm_global_free_t _vm_global_free = NULL;

void vm_global_free(void* ptr)
{
    if (NULL == _vm_global_free)
        _vm_global_free = (_vm_global_free_t)vm_get_sym_entry("vm_global_free");

    if (NULL != _vm_global_free)
        _vm_global_free(ptr);

    
}
