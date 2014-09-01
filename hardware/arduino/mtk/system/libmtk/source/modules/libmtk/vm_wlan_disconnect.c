#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_disconnect_t)(vm_wlan_cb_func_ptr callback, void *user_data);
_vm_wlan_disconnect_t _vm_wlan_disconnect = NULL;

VMINT vm_wlan_disconnect(vm_wlan_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_disconnect)
        _vm_wlan_disconnect = (_vm_wlan_disconnect_t)vm_get_sym_entry("vm_wlan_disconnect");
    if (NULL != _vm_wlan_disconnect)
        return _vm_wlan_disconnect(callback,user_data);
    return (VMINT)-1;
}