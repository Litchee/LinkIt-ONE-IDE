#include "vmsys.h"
#include "vmbtnotify.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_bt_noti_check_connection_t)(void);
_vm_srv_bt_noti_check_connection_t _vm_srv_bt_noti_check_connection = NULL;

VMINT vm_srv_bt_noti_check_connection(void)
{
    if (NULL == _vm_srv_bt_noti_check_connection)
        _vm_srv_bt_noti_check_connection = (_vm_srv_bt_noti_check_connection_t)vm_get_sym_entry("vm_srv_bt_noti_check_connection");
    if (NULL != _vm_srv_bt_noti_check_connection)
        return _vm_srv_bt_noti_check_connection();
    return (VMINT)-1;
}