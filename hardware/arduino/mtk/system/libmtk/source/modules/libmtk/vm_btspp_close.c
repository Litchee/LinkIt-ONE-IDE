#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_close_t)(VMINT res_hd);
_vm_btspp_close_t _vm_btspp_close = NULL;
VMINT vm_btspp_close(VMINT res_hd)
{
    if (NULL == _vm_btspp_close)
        _vm_btspp_close = (_vm_btspp_close_t)vm_get_sym_entry("vm_btspp_close");

    if (NULL != _vm_btspp_close)
        return _vm_btspp_close(res_hd);

    return (VMINT)-1;
}
