#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_delete_msg_list_t)(vm_sms_box_enum box_type, vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func, void* user_data);
_vm_sms_delete_msg_list_t _vm_sms_delete_msg_list = NULL;

VMINT vm_sms_delete_msg_list(vm_sms_box_enum box_type, vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func, void* user_data)
{
    if (NULL == _vm_sms_delete_msg_list)
        _vm_sms_delete_msg_list = (_vm_sms_delete_msg_list_t)vm_get_sym_entry("vm_sms_delete_msg_list");

    if (NULL != _vm_sms_delete_msg_list)
        return _vm_sms_delete_msg_list(box_type,sim_id,callback_func,user_data);

    return (VMINT )-1;
}
