#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_set_interrupt_event_handler_t)(vm_mms_event_enum event, vm_mms_interrupt_callback callback, void* user_data);
_vm_mms_set_interrupt_event_handler_t _vm_mms_set_interrupt_event_handler = NULL;

VMINT vm_mms_set_interrupt_event_handler(vm_mms_event_enum event, vm_mms_interrupt_callback callback, void* user_data)
{
    if (NULL == _vm_mms_set_interrupt_event_handler)
        _vm_mms_set_interrupt_event_handler = (_vm_mms_set_interrupt_event_handler_t)vm_get_sym_entry("vm_mms_set_interrupt_event_handler");

    if (NULL != _vm_mms_set_interrupt_event_handler)
        return _vm_mms_set_interrupt_event_handler(event,callback,user_data);

    return (VMINT )-1;
}
