#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_time_t)(vm_time_t* time);
_vm_get_time_t _vm_get_time = NULL;

VMINT vm_get_time(vm_time_t* time)
{
    if (NULL == _vm_get_time)
        _vm_get_time = (_vm_get_time_t)vm_get_sym_entry("vm_get_time");

    if (NULL != _vm_get_time)
        return _vm_get_time(time);

    return (VMINT )-1;
}
