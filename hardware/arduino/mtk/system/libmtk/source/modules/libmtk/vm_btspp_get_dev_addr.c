#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_get_dev_addr_t)(VMINT conn_id, vm_srv_bt_cm_bt_addr * bt_addr);
_vm_btspp_get_dev_addr_t _vm_btspp_get_dev_addr = NULL;
VMINT vm_btspp_get_dev_addr(VMINT conn_id, vm_srv_bt_cm_bt_addr * bt_addr)
{
    if (NULL == _vm_btspp_get_dev_addr)
        _vm_btspp_get_dev_addr = (_vm_btspp_get_dev_addr_t)vm_get_sym_entry("vm_btspp_get_dev_addr");

    if (NULL != _vm_btspp_get_dev_addr)
        return _vm_btspp_get_dev_addr(conn_id,bt_addr);

    return (VMINT)-1;
}
