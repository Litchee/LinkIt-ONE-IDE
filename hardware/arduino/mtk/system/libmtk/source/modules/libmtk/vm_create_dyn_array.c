#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_dyn_array_t* (*_vm_create_dyn_array_t)(VMINT init_size, VMINT inc_size, VMINT block_size);
_vm_create_dyn_array_t _vm_create_dyn_array = NULL;

vm_dyn_array_t* vm_create_dyn_array(VMINT init_size, VMINT inc_size, VMINT block_size)
{
    if (NULL == _vm_create_dyn_array)
        _vm_create_dyn_array = (_vm_create_dyn_array_t)vm_get_sym_entry("vm_create_dyn_array");

    if (NULL != _vm_create_dyn_array)
        return _vm_create_dyn_array(init_size,inc_size,block_size);

    return (vm_dyn_array_t* )-1;
}
