#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_dereg_noti_t)(VMINT noti_type, vm_wlan_noti_func_ptr callback, void *user_data);
_vm_wlan_dereg_noti_t _vm_wlan_dereg_noti = NULL;

VMINT vm_wlan_dereg_noti(VMINT noti_type, vm_wlan_noti_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_dereg_noti)
        _vm_wlan_dereg_noti = (_vm_wlan_dereg_noti_t)vm_get_sym_entry("vm_wlan_dereg_noti");
    if (NULL != _vm_wlan_dereg_noti)
        return _vm_wlan_dereg_noti(noti_type,callback,user_data);
    return (VMINT)-1;
}