#include "vmsys.h"
#include "vmbtnotify.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_bt_noti_get_bt_device_addr_t)(VMINT cntx_chnl, vm_srv_bt_cm_bt_addr *bt_addr);
_vm_bt_noti_get_bt_device_addr_t _vm_bt_noti_get_bt_device_addr = NULL;

VMINT vm_bt_noti_get_bt_device_addr(VMINT cntx_chnl, vm_srv_bt_cm_bt_addr *bt_addr)
{
    if (NULL == _vm_bt_noti_get_bt_device_addr)
        _vm_bt_noti_get_bt_device_addr = (_vm_bt_noti_get_bt_device_addr_t)vm_get_sym_entry("vm_bt_noti_get_bt_device_addr");
    if (NULL != _vm_bt_noti_get_bt_device_addr)
        return _vm_bt_noti_get_bt_device_addr(cntx_chnl,bt_addr);
    return (VMINT)-1;
}