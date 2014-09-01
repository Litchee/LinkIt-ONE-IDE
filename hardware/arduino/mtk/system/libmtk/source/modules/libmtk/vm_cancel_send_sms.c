#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_cancel_send_sms_t)(void);
_vm_cancel_send_sms_t _vm_cancel_send_sms = NULL;

void vm_cancel_send_sms(void)
{
    if (NULL == _vm_cancel_send_sms)
        _vm_cancel_send_sms = (_vm_cancel_send_sms_t)vm_get_sym_entry("vm_cancel_send_sms");

    if (NULL != _vm_cancel_send_sms)
        _vm_cancel_send_sms();

    
}
