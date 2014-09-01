#include "vmsys.h"
#include "vmfota.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_srv_funet_flag_enum (*_vm_srv_funet_trigger_t)(VMWCHAR * file_name, vm_srv_funet_update_type_enum update_type);
_vm_srv_funet_trigger_t _vm_srv_funet_trigger = NULL;

vm_srv_funet_flag_enum vm_srv_funet_trigger(VMWCHAR * file_name, vm_srv_funet_update_type_enum update_type)
{
    if (NULL == _vm_srv_funet_trigger)
        _vm_srv_funet_trigger = (_vm_srv_funet_trigger_t)vm_get_sym_entry("vm_srv_funet_trigger");

    if (NULL != _vm_srv_funet_trigger)
        return _vm_srv_funet_trigger(file_name,update_type);
        
    return (vm_srv_funet_flag_enum )-1;
}
