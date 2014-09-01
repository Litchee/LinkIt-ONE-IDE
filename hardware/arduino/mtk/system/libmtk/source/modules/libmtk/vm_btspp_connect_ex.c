#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_connect_ex_t)(VMINT res_hd, const vm_srv_bt_cm_bt_addr * bt_addr, void * buf, VMUINT tx_size, VMUINT rx_size, vm_srv_spp_connect_type conn_type, VMUINT16 uuid );
_vm_btspp_connect_ex_t _vm_btspp_connect_ex = NULL;
VMINT vm_btspp_connect_ex(VMINT res_hd, const vm_srv_bt_cm_bt_addr * bt_addr, void * buf, VMUINT tx_size, VMUINT rx_size, vm_srv_spp_connect_type conn_type, VMUINT16 uuid )
{
    if (NULL == _vm_btspp_connect_ex)
        _vm_btspp_connect_ex = (_vm_btspp_connect_ex_t)vm_get_sym_entry("vm_btspp_connect_ex");

    if (NULL != _vm_btspp_connect_ex)
        return _vm_btspp_connect_ex(res_hd,bt_addr,buf,tx_size,rx_size,conn_type, uuid);

    return (VMINT)-1;
}
