#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dyn_array_add_t)(vm_dyn_array_t *array, void* data);
_vm_dyn_array_add_t _vm_dyn_array_add = NULL;

VMINT vm_dyn_array_add(vm_dyn_array_t *array, void* data)
{
    if (NULL == _vm_dyn_array_add)
        _vm_dyn_array_add = (_vm_dyn_array_add_t)vm_get_sym_entry("vm_dyn_array_add");

    if (NULL != _vm_dyn_array_add)
        return _vm_dyn_array_add(array,data);

    return (VMINT )-1;
}
