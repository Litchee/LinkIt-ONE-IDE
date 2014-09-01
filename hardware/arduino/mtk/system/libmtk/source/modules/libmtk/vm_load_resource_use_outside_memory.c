#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_load_resource_use_outside_memory_t)(VMWSTR filename, char *res_name, void* buffer, VMINT buffer_size, vm_res_read_hint_struct* hint);
_vm_load_resource_use_outside_memory_t _vm_load_resource_use_outside_memory = NULL;

VMBOOL vm_load_resource_use_outside_memory(VMWSTR filename, char *res_name, void* buffer, VMINT buffer_size, vm_res_read_hint_struct* hint)
{
    if (NULL == _vm_load_resource_use_outside_memory)
        _vm_load_resource_use_outside_memory = (_vm_load_resource_use_outside_memory_t)vm_get_sym_entry("vm_load_resource_use_outside_memory");

    if (NULL != _vm_load_resource_use_outside_memory)
        return _vm_load_resource_use_outside_memory(filename,res_name,buffer,buffer_size,hint);

    return 0;
}
