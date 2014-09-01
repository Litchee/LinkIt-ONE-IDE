#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_get_connected_ap_info_t)(void *info, VMINT info_type);
_vm_wlan_get_connected_ap_info_t _vm_wlan_get_connected_ap_info = NULL;

VMINT vm_wlan_get_connected_ap_info(void *info, VMINT info_type)
{
    if (NULL == _vm_wlan_get_connected_ap_info)
        _vm_wlan_get_connected_ap_info = (_vm_wlan_get_connected_ap_info_t)vm_get_sym_entry("vm_wlan_get_connected_ap_info");
    if (NULL != _vm_wlan_get_connected_ap_info)
        return _vm_wlan_get_connected_ap_info(info,info_type);
    return (VMINT)-1;
}