#include "vmsys.h"
#include "vmbtnotify.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_bt_noti_send_ex_t)(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR sender[VM_MAX_IOER], const VMCHAR receiver[VM_MAX_IOER], VMINT data_type, const VMBYTE *data, VMINT len);
_vm_srv_bt_noti_send_ex_t _vm_srv_bt_noti_send_ex = NULL;

VMINT vm_srv_bt_noti_send_ex(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR sender[VM_MAX_IOER], const VMCHAR receiver[VM_MAX_IOER], VMINT data_type, const VMBYTE *data, VMINT len)
{
    if (NULL == _vm_srv_bt_noti_send_ex)
        _vm_srv_bt_noti_send_ex = (_vm_srv_bt_noti_send_ex_t)vm_get_sym_entry("vm_srv_bt_noti_send_ex");
    if (NULL != _vm_srv_bt_noti_send_ex)
        return _vm_srv_bt_noti_send_ex(bt_addr,sender,receiver,data_type,data,len);
    return (VMINT)-1;
}