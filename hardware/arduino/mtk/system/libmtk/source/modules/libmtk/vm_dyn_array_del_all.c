#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dyn_array_del_all_t)(vm_dyn_array_t *array);
_vm_dyn_array_del_all_t _vm_dyn_array_del_all = NULL;

VMINT vm_dyn_array_del_all(vm_dyn_array_t *array)
{
    if (NULL == _vm_dyn_array_del_all)
        _vm_dyn_array_del_all = (_vm_dyn_array_del_all_t)vm_get_sym_entry("vm_dyn_array_del_all");

    if (NULL != _vm_dyn_array_del_all)
        return _vm_dyn_array_del_all(array);

    return (VMINT )-1;
}
