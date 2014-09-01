#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_get_ip_info_t)(vm_wlan_ip_info_struct* ip_info);
_vm_wlan_get_ip_info_t _vm_wlan_get_ip_info = NULL;

VMINT vm_wlan_get_ip_info(vm_wlan_ip_info_struct* ip_info)
{
    if (NULL == _vm_wlan_get_ip_info)
        _vm_wlan_get_ip_info = (_vm_wlan_get_ip_info_t)vm_get_sym_entry("vm_wlan_get_ip_info");
    if (NULL != _vm_wlan_get_ip_info)
        return _vm_wlan_get_ip_info(ip_info);
    return (VMINT)-1;
}