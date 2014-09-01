#include "vmsys.h"
#include "vmsettings.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void  (*_vm_idle_swatch_pedometer_register_callback_t)(vm_idle_swatch_pedometer_cb event_hdlr);
_vm_idle_swatch_pedometer_register_callback_t _vm_idle_swatch_pedometer_register_callback = NULL;
void vm_idle_swatch_pedometer_register_callback(vm_idle_swatch_pedometer_cb event_hdlr)

{
    if (NULL == _vm_idle_swatch_pedometer_register_callback)
        _vm_idle_swatch_pedometer_register_callback = (_vm_idle_swatch_pedometer_register_callback_t)vm_get_sym_entry("vm_idle_swatch_pedometer_register_callback");
    if (NULL != _vm_idle_swatch_pedometer_register_callback)
        _vm_idle_swatch_pedometer_register_callback(event_hdlr);
}