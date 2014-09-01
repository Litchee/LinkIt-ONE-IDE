#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_connect_t)(VMINT res_hd, const vm_srv_bt_cm_bt_addr * bt_addr, void * buf, VMUINT tx_size, VMUINT rx_size, VMUINT16 uuid );
_vm_btspp_connect_t _vm_btspp_connect = NULL;
VMINT vm_btspp_connect(VMINT res_hd, const vm_srv_bt_cm_bt_addr * bt_addr, void * buf, VMUINT tx_size, VMUINT rx_size, VMUINT16 uuid )
{
    if (NULL == _vm_btspp_connect)
        _vm_btspp_connect = (_vm_btspp_connect_t)vm_get_sym_entry("vm_btspp_connect");

    if (NULL != _vm_btspp_connect)
        return _vm_btspp_connect(res_hd,bt_addr,buf,tx_size,rx_size, uuid);

    return (VMINT)-1;
}
