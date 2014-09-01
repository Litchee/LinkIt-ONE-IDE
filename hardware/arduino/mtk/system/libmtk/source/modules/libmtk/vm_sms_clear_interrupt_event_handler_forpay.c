#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_clear_interrupt_event_handler_forpay_t)(vm_sms_event_enum event_id, VmSmsEventFunc event_func, void* user_data);
_vm_sms_clear_interrupt_event_handler_forpay_t _vm_sms_clear_interrupt_event_handler_forpay = NULL;

VMINT vm_sms_clear_interrupt_event_handler_forpay(vm_sms_event_enum event_id, VmSmsEventFunc event_func, void* user_data)
{
    if (NULL == _vm_sms_clear_interrupt_event_handler_forpay)
        _vm_sms_clear_interrupt_event_handler_forpay = (_vm_sms_clear_interrupt_event_handler_forpay_t)vm_get_sym_entry("vm_sms_clear_interrupt_event_handler_forpay");

    if (NULL != _vm_sms_clear_interrupt_event_handler_forpay)
        return _vm_sms_clear_interrupt_event_handler_forpay(event_id,event_func,user_data);

    return (VMINT )-1;
}
