#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dyn_array_del_t)(vm_dyn_array_t *array, VMINT idx);
_vm_dyn_array_del_t _vm_dyn_array_del = NULL;

VMINT vm_dyn_array_del(vm_dyn_array_t *array, VMINT idx)
{
    if (NULL == _vm_dyn_array_del)
        _vm_dyn_array_del = (_vm_dyn_array_del_t)vm_get_sym_entry("vm_dyn_array_del");

    if (NULL != _vm_dyn_array_del)
        return _vm_dyn_array_del(array,idx);

    return (VMINT )-1;
}
