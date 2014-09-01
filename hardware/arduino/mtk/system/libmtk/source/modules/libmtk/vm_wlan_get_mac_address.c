#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_get_mac_address_t)(vm_wlan_prof_str_info_qry_struct *mac_address_out);
_vm_wlan_get_mac_address_t _vm_wlan_get_mac_address = NULL;

VMINT vm_wlan_get_mac_address(vm_wlan_prof_str_info_qry_struct *mac_address_out)
{
    if (NULL == _vm_wlan_get_mac_address)
        _vm_wlan_get_mac_address = (_vm_wlan_get_mac_address_t)vm_get_sym_entry("vm_wlan_get_mac_address");
    if (NULL != _vm_wlan_get_mac_address)
        return _vm_wlan_get_mac_address(mac_address_out);
    return (VMINT)-1;
}