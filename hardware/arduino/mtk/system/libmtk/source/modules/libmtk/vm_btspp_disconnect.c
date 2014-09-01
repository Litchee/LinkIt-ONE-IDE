#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_disconnect_t)(VMINT conn_id);
_vm_btspp_disconnect_t _vm_btspp_disconnect = NULL;
VMINT vm_btspp_disconnect(VMINT conn_id)
{
    if (NULL == _vm_btspp_disconnect)
        _vm_btspp_disconnect = (_vm_btspp_disconnect_t)vm_get_sym_entry("vm_btspp_disconnect");

    if (NULL != _vm_btspp_disconnect)
        return _vm_btspp_disconnect(conn_id);

    return (VMINT)-1;
}
