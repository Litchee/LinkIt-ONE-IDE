#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_roaming_set_t)(VMINT enable_roaming, vm_wlan_cb_func_ptr callback, void *user_data);
_vm_wlan_roaming_set_t _vm_wlan_roaming_set = NULL;

VMINT vm_wlan_roaming_set(VMINT enable_roaming, vm_wlan_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_roaming_set)
        _vm_wlan_roaming_set = (_vm_wlan_roaming_set_t)vm_get_sym_entry("vm_wlan_roaming_set");
    if (NULL != _vm_wlan_roaming_set)
        return _vm_wlan_roaming_set(enable_roaming,callback,user_data);
    return (VMINT)-1;
}