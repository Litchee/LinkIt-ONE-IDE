#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_get_sc_address_syn_t)(vm_sms_get_sc_addr_cb_t * vm_sc_addr, vm_sms_sim_enum sim_id);
_vm_sms_get_sc_address_syn_t _vm_sms_get_sc_address_syn = NULL;

VMINT vm_sms_get_sc_address_syn(vm_sms_get_sc_addr_cb_t * vm_sc_addr, vm_sms_sim_enum sim_id)
{
    if (NULL == _vm_sms_get_sc_address_syn)
        _vm_sms_get_sc_address_syn = (_vm_sms_get_sc_address_syn_t)vm_get_sym_entry("vm_sms_get_sc_address_syn");

    if (NULL != _vm_sms_get_sc_address_syn)
        return _vm_sms_get_sc_address_syn(vm_sc_addr,sim_id);

    return (VMINT )-1;
}
