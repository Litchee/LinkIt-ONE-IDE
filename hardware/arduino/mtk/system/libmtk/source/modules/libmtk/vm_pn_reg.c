#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_reg_t)(vm_pn_cb cb, void* user_data);
_vm_pn_reg_t _vm_pn_reg = NULL;

VMINT vm_pn_reg(vm_pn_cb cb, void* user_data)
{
    if (NULL == _vm_pn_reg)
        _vm_pn_reg = (_vm_pn_reg_t)vm_get_sym_entry("vm_pn_reg");

    if (NULL != _vm_pn_reg)
        return _vm_pn_reg(cb,user_data);

    return (VMINT)-1;
}