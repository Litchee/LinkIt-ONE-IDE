#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_delete_msg_forpay_t)(VMUINT16 msg_id, VmSmsCallbackFunc callback_func, void* user_data);
_vm_sms_delete_msg_forpay_t _vm_sms_delete_msg_forpay = NULL;

VMINT vm_sms_delete_msg_forpay(VMUINT16 msg_id, VmSmsCallbackFunc callback_func, void* user_data)
{
    if (NULL == _vm_sms_delete_msg_forpay)
        _vm_sms_delete_msg_forpay = (_vm_sms_delete_msg_forpay_t)vm_get_sym_entry("vm_sms_delete_msg_forpay");

    if (NULL != _vm_sms_delete_msg_forpay)
        return _vm_sms_delete_msg_forpay(msg_id,callback_func,user_data);

    return (VMINT )-1;
}
