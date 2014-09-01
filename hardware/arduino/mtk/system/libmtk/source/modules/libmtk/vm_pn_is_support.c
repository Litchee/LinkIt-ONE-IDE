#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_is_support_t)(void);
_vm_pn_is_support_t _vm_pn_is_support = NULL;

VMINT vm_pn_is_support(void)
{
    if (NULL == _vm_pn_is_support)
        _vm_pn_is_support = (_vm_pn_is_support_t)vm_get_sym_entry("vm_pn_is_support");

    if (NULL != _vm_pn_is_support)
        return _vm_pn_is_support();

    return (VMINT)-1;
}