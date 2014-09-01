#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_launch_t)(vm_mms_launch_data* data, VMINT data_size);
_vm_mms_launch_t _vm_mms_launch = NULL;

VMINT vm_mms_launch(vm_mms_launch_data* data, VMINT data_size)
{
    if (NULL == _vm_mms_launch)
        _vm_mms_launch = (_vm_mms_launch_t)vm_get_sym_entry("vm_mms_launch");

    if (NULL != _vm_mms_launch)
        return _vm_mms_launch(data,data_size);

    return (VMINT )-1;
}
