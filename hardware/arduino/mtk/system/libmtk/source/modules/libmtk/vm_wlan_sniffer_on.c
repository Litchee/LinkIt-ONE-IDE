#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_sniffer_on_t)(vm_wlan_sniffer_on_cfg_struct *sniffer_on_config, vm_wlan_sniffer_on_cb_func_ptr callback, void *user_data);
_vm_wlan_sniffer_on_t _vm_wlan_sniffer_on = NULL;

VMINT vm_wlan_sniffer_on(vm_wlan_sniffer_on_cfg_struct *sniffer_on_config, vm_wlan_sniffer_on_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_sniffer_on)
        _vm_wlan_sniffer_on = (_vm_wlan_sniffer_on_t)vm_get_sym_entry("vm_wlan_sniffer_on");
    if (NULL != _vm_wlan_sniffer_on)
        return _vm_wlan_sniffer_on(sniffer_on_config,callback,user_data);
    return (VMINT)-1;
}