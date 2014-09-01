#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_get_modify_time_t)(const VMWSTR filename, vm_time_t * modify_time);
_vm_file_get_modify_time_t _vm_file_get_modify_time = NULL;

VMINT vm_file_get_modify_time(const VMWSTR filename, vm_time_t * modify_time)
{
    if (NULL == _vm_file_get_modify_time)
        _vm_file_get_modify_time = (_vm_file_get_modify_time_t)vm_get_sym_entry("vm_file_get_modify_time");

    if (NULL != _vm_file_get_modify_time)
        return _vm_file_get_modify_time(filename,modify_time);

    return (VMINT )-1;
}
