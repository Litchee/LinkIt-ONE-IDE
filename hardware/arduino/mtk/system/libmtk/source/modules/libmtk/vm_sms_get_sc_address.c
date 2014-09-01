#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sms_get_sc_address_t)( vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func, void* user_data);
_vm_sms_get_sc_address_t _vm_sms_get_sc_address = NULL;

VMINT vm_sms_get_sc_address( vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func, void* user_data)
{
    if (NULL == _vm_sms_get_sc_address)
        _vm_sms_get_sc_address = (_vm_sms_get_sc_address_t)vm_get_sym_entry("vm_sms_get_sc_address");

    if (NULL != _vm_sms_get_sc_address)
        return _vm_sms_get_sc_address(sim_id,callback_func,user_data);

    return (VMINT )-1;
}
