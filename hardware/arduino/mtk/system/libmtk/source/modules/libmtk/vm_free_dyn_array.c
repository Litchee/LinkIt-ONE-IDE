#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_free_dyn_array_t)(vm_dyn_array_t *array);
_vm_free_dyn_array_t _vm_free_dyn_array = NULL;

void vm_free_dyn_array(vm_dyn_array_t *array)
{
    if (NULL == _vm_free_dyn_array)
        _vm_free_dyn_array = (_vm_free_dyn_array_t)vm_get_sym_entry("vm_free_dyn_array");

    if (NULL != _vm_free_dyn_array)
        _vm_free_dyn_array(array);

    
}
