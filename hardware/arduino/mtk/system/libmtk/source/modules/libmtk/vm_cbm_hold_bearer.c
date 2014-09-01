#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_cbm_hold_bearer_t)(vm_res_type_t type, VMINT hdl);
_vm_cbm_hold_bearer_t _vm_cbm_hold_bearer = NULL;

VMINT vm_cbm_hold_bearer(vm_res_type_t type, VMINT hdl)
{
    if (NULL == _vm_cbm_hold_bearer)
        _vm_cbm_hold_bearer = (_vm_cbm_hold_bearer_t)vm_get_sym_entry("vm_cbm_hold_bearer");

    if (NULL != _vm_cbm_hold_bearer)
        return _vm_cbm_hold_bearer(type,hdl);

    return (VMINT)-1;
}