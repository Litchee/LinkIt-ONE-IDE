#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_mode_set_t)(vm_wlan_set_mode_enum mode, vm_wlan_cb_func_ptr callback, void *user_data);
_vm_wlan_mode_set_t _vm_wlan_mode_set = NULL;

VMINT vm_wlan_mode_set(vm_wlan_set_mode_enum mode, vm_wlan_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_mode_set)
        _vm_wlan_mode_set = (_vm_wlan_mode_set_t)vm_get_sym_entry("vm_wlan_mode_set");
    if (NULL != _vm_wlan_mode_set)
        return _vm_wlan_mode_set(mode,callback,user_data);
    return (VMINT)-1;
}