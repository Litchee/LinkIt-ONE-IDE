#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_connect_t)(VMUINT32 prof_id, vm_wlan_conn_res_cb_func_ptr callback, void *user_data);
_vm_wlan_prof_connect_t _vm_wlan_prof_connect = NULL;

VMINT vm_wlan_prof_connect(VMUINT32 prof_id, vm_wlan_conn_res_cb_func_ptr callback, void *user_data)
{
    if (NULL == _vm_wlan_prof_connect)
        _vm_wlan_prof_connect = (_vm_wlan_prof_connect_t)vm_get_sym_entry("vm_wlan_prof_connect");
    if (NULL != _vm_wlan_prof_connect)
        return _vm_wlan_prof_connect(prof_id,callback,user_data);
    return (VMINT)-1;
}