#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_scan_get_param_t)(void *param, VMINT32 param_type);
_vm_wlan_scan_get_param_t _vm_wlan_scan_get_param = NULL;

VMINT vm_wlan_scan_get_param(void *param, VMINT32 param_type)
{
    if (NULL == _vm_wlan_scan_get_param)
        _vm_wlan_scan_get_param = (_vm_wlan_scan_get_param_t)vm_get_sym_entry("vm_wlan_scan_get_param");
    if (NULL != _vm_wlan_scan_get_param)
        return _vm_wlan_scan_get_param(param,param_type);
    return (VMINT)-1;
}