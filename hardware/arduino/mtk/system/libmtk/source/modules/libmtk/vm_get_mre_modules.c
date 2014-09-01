#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_mre_modules_t)(vm_module_struct *modules, VMUINT size);
_vm_get_mre_modules_t _vm_get_mre_modules = NULL;

VMINT vm_get_mre_modules(vm_module_struct *modules, VMUINT size)
{
    if (NULL == _vm_get_mre_modules)
        _vm_get_mre_modules = (_vm_get_mre_modules_t)vm_get_sym_entry("vm_get_mre_modules");

    if (NULL != _vm_get_mre_modules)
        return _vm_get_mre_modules(modules,size);

    return (VMINT )-1;
}
