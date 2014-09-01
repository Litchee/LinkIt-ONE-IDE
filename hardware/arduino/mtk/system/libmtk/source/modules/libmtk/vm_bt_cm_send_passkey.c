#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_bt_cm_send_passkey_t)(vm_srv_bt_cm_bt_addr* dev_addr, VMUINT8* dev_passkey, VMBOOL result);
_vm_bt_cm_send_passkey_t _vm_bt_cm_send_passkey = NULL;

VMINT vm_bt_cm_send_passkey(vm_srv_bt_cm_bt_addr* dev_addr, VMUINT8* dev_passkey, VMBOOL result)
{
    if (NULL == _vm_bt_cm_send_passkey)
        _vm_bt_cm_send_passkey = (_vm_bt_cm_send_passkey_t)vm_get_sym_entry("vm_bt_cm_send_passkey");
    if (NULL != _vm_bt_cm_send_passkey)
        return _vm_bt_cm_send_passkey(dev_addr,dev_passkey,result);
    return (VMINT)-1;
}