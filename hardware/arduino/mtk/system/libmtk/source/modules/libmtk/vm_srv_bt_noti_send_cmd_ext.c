#include "vmsys.h"
#include "vmbtnotify.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_bt_noti_send_cmd_ext_t)(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR reader[VM_MAX_IOER], VMINT data_type, const VMBYTE *data, VMINT len);
_vm_srv_bt_noti_send_cmd_ext_t _vm_srv_bt_noti_send_cmd_ext = NULL;

VMINT vm_srv_bt_noti_send_cmd_ext(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR reader[VM_MAX_IOER], VMINT data_type, const VMBYTE *data, VMINT len)
{
    if (NULL == _vm_srv_bt_noti_send_cmd_ext)
        _vm_srv_bt_noti_send_cmd_ext = (_vm_srv_bt_noti_send_cmd_ext_t)vm_get_sym_entry("vm_srv_bt_noti_send_cmd_ext");
    if (NULL != _vm_srv_bt_noti_send_cmd_ext)
        return _vm_srv_bt_noti_send_cmd_ext(bt_addr,reader,data_type,data,len);
    return (VMINT)-1;
}