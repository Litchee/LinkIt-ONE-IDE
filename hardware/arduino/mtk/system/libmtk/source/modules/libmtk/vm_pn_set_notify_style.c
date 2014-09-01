#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_set_notify_style_t)(vm_srv_pns_notify_switch OnOff, vm_srv_pns_notify_style style);
_vm_pn_set_notify_style_t _vm_pn_set_notify_style = NULL;

VMINT vm_pn_set_notify_style(vm_srv_pns_notify_switch OnOff, vm_srv_pns_notify_style style)
{
    if (NULL == _vm_pn_set_notify_style)
        _vm_pn_set_notify_style = (_vm_pn_set_notify_style_t)vm_get_sym_entry("vm_pn_set_notify_style");

    if (NULL != _vm_pn_set_notify_style)
        return _vm_pn_set_notify_style(OnOff,style);

    return (VMINT)-1;
}