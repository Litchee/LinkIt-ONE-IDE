#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_sniffer_off_t)(vm_wlan_sniffer_off_cb_func_ptr callback, void *user_data);
_vm_wlan_sniffer_off_t _vm_wlan_sniffer_off = NULL;

VMINT vm_wlan_sniffer_off(vm_wlan_sniffer_off_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_sniffer_off)
        _vm_wlan_sniffer_off = (_vm_wlan_sniffer_off_t)vm_get_sym_entry("vm_wlan_sniffer_off");
    if (NULL != _vm_wlan_sniffer_off)
        return _vm_wlan_sniffer_off(callback,user_data);
    return (VMINT)-1;
}