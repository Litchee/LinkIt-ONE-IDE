#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_bind_t)(VMINT res_hd, VMUINT16 uuid);
_vm_btspp_bind_t _vm_btspp_bind = NULL;
VMINT vm_btspp_bind(VMINT res_hd, VMUINT16 uuid)
{
    if (NULL == _vm_btspp_bind)
        _vm_btspp_bind = (_vm_btspp_bind_t)vm_get_sym_entry("vm_btspp_bind");

    if (NULL != _vm_btspp_bind)
        return _vm_btspp_bind(res_hd, uuid);

    return (VMINT)-1;
}
