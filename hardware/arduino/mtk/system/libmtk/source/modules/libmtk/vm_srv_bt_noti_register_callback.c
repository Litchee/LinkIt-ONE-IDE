#include "vmsys.h"
#include "vmbtnotify.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_bt_noti_register_callback_t)(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR sender[VM_MAX_IOER], vm_srv_bt_noti_callback cb);
_vm_srv_bt_noti_register_callback_t _vm_srv_bt_noti_register_callback = NULL;

VMINT vm_srv_bt_noti_register_callback(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR sender[VM_MAX_IOER], vm_srv_bt_noti_callback cb)
{
    if (NULL == _vm_srv_bt_noti_register_callback)
        _vm_srv_bt_noti_register_callback = (_vm_srv_bt_noti_register_callback_t)vm_get_sym_entry("vm_srv_bt_noti_register_callback");
    if (NULL != _vm_srv_bt_noti_register_callback)
        return _vm_srv_bt_noti_register_callback(bt_addr,sender,cb);
    return (VMINT)-1;
}