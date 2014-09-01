#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_accept_t)(VMINT conn_id, void * buf, VMUINT tx_size, VMUINT rx_size );
_vm_btspp_accept_t _vm_btspp_accept = NULL;
VMINT vm_btspp_accept(VMINT conn_id, void * buf, VMUINT tx_size, VMUINT rx_size )
{
    if (NULL == _vm_btspp_accept)
        _vm_btspp_accept = (_vm_btspp_accept_t)vm_get_sym_entry("vm_btspp_accept");

    if (NULL != _vm_btspp_accept)
        return _vm_btspp_accept(conn_id,buf,tx_size,rx_size);

    return (VMINT)-1;
}
