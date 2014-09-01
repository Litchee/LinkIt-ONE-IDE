#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_send_sms_t)(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result));
_vm_send_sms_t _vm_send_sms = NULL;

VMINT vm_send_sms(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result))
{
    if (NULL == _vm_send_sms)
        _vm_send_sms = (_vm_send_sms_t)vm_get_sym_entry("vm_send_sms");

    if (NULL != _vm_send_sms)
        return _vm_send_sms(phone_number,content,callback);

    return (VMINT )-1;
}
