#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_scan_set_param_t)(void *param, VMINT32 param_type, vm_wlan_cb_func_ptr callback, void *user_data);
_vm_wlan_scan_set_param_t _vm_wlan_scan_set_param = NULL;

VMINT vm_wlan_scan_set_param(void *param, VMINT32 param_type, vm_wlan_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_scan_set_param)
        _vm_wlan_scan_set_param = (_vm_wlan_scan_set_param_t)vm_get_sym_entry("vm_wlan_scan_set_param");
    if (NULL != _vm_wlan_scan_set_param)
        return _vm_wlan_scan_set_param(param,param_type,callback,user_data);
    return (VMINT)-1;
}