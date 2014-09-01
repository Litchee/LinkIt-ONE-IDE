#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_reject_t)(VMINT conn_id);
_vm_btspp_reject_t _vm_btspp_reject = NULL;
VMINT vm_btspp_reject(VMINT conn_id)
{
    if (NULL == _vm_btspp_reject)
        _vm_btspp_reject = (_vm_btspp_reject_t)vm_get_sym_entry("vm_btspp_reject");

    if (NULL != _vm_btspp_reject)
        return _vm_btspp_reject(conn_id);

    return (VMINT)-1;
}
