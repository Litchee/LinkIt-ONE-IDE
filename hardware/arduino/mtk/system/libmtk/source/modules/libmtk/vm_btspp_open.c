#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_open_t)(VMUINT evt_mask, void (*callback)(VMUINT evt, void * param, void * user_data), void * user_data);
_vm_btspp_open_t _vm_btspp_open = NULL;
VMINT vm_btspp_open(VMUINT evt_mask, void (*callback)(VMUINT evt, void * param, void * user_data), void * user_data)
{
    if (NULL == _vm_btspp_open)
        _vm_btspp_open = (_vm_btspp_open_t)vm_get_sym_entry("vm_btspp_open");

    if (NULL != _vm_btspp_open)
        return _vm_btspp_open(evt_mask,callback,user_data);

    return (VMINT)-1;
}
