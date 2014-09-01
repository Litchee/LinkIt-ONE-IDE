#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_launch_t)(vm_sms_launch_data* data, VMINT data_size);
_vm_sms_launch_t _vm_sms_launch = NULL;

VMINT vm_sms_launch(vm_sms_launch_data* data, VMINT data_size)
{
    if (NULL == _vm_sms_launch)
        _vm_sms_launch = (_vm_sms_launch_t)vm_get_sym_entry("vm_sms_launch");

    if (NULL != _vm_sms_launch)
        return _vm_sms_launch(data, data_size);
		return -1;
    
}
