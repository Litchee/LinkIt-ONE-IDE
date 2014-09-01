#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_sla_custom_logging_t)(VMSTR custom_label, vm_sla_action_type action);
_vm_sla_custom_logging_t _vm_sla_custom_logging = NULL;

void vm_sla_custom_logging(VMSTR custom_label, vm_sla_action_type action)
{
    if (NULL == _vm_sla_custom_logging)
        _vm_sla_custom_logging = (_vm_sla_custom_logging_t)vm_get_sym_entry("vm_sla_custom_logging");

    if (NULL != _vm_sla_custom_logging)
        _vm_sla_custom_logging(custom_label, action);
}
