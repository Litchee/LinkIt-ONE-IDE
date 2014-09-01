#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_scan_t)(vm_wlan_scan_res_cb_func_ptr callback, void *user_data);
_vm_wlan_scan_t _vm_wlan_scan = NULL;

VMINT vm_wlan_scan(vm_wlan_scan_res_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_scan)
        _vm_wlan_scan = (_vm_wlan_scan_t)vm_get_sym_entry("vm_wlan_scan");
    if (NULL != _vm_wlan_scan)
        return _vm_wlan_scan(callback,user_data);
    return (VMINT)-1;
}