#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_delete_msg_t)(VMUINT16 msg_id, VmSmsCallbackFunc callback_func, void* user_data);
_vm_sms_delete_msg_t _vm_sms_delete_msg = NULL;

VMINT vm_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func, void* user_data)
{
    if (NULL == _vm_sms_delete_msg)
        _vm_sms_delete_msg = (_vm_sms_delete_msg_t)vm_get_sym_entry("vm_sms_delete_msg");

    if (NULL != _vm_sms_delete_msg)
        return _vm_sms_delete_msg(msg_id,callback_func,user_data);

    return (VMINT )-1;
}
