#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_get_global_setting_t)(void);
_vm_pn_get_global_setting_t _vm_pn_get_global_setting = NULL;

VMINT vm_pn_get_global_setting(void)
{
    if (NULL == _vm_pn_get_global_setting)
        _vm_pn_get_global_setting = (_vm_pn_get_global_setting_t)vm_get_sym_entry("vm_pn_get_global_setting");

    if (NULL != _vm_pn_get_global_setting)
        return _vm_pn_get_global_setting();

    return (VMINT)-1;
}