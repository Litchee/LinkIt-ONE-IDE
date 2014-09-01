#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_get_msg_id_list_t)(vm_sms_query_t* query_data, VmSmsCallbackFunc callback_func, void* user_data);
_vm_sms_get_msg_id_list_t _vm_sms_get_msg_id_list = NULL;

VMINT vm_sms_get_msg_id_list(vm_sms_query_t* query_data, VmSmsCallbackFunc callback_func, void* user_data)
{
    if (NULL == _vm_sms_get_msg_id_list)
        _vm_sms_get_msg_id_list = (_vm_sms_get_msg_id_list_t)vm_get_sym_entry("vm_sms_get_msg_id_list");

    if (NULL != _vm_sms_get_msg_id_list)
        return _vm_sms_get_msg_id_list(query_data,callback_func,user_data);

    return (VMINT )-1;
}
