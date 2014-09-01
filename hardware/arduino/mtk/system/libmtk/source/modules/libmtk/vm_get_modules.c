#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_modules_t)(vm_module_struct *modules, VMUINT size);
_vm_get_modules_t _vm_get_modules = NULL;

VMINT vm_get_modules(vm_module_struct *modules, VMUINT size)
{
    if (NULL == _vm_get_modules)
        _vm_get_modules = (_vm_get_modules_t)vm_get_sym_entry("vm_get_modules");

    if (NULL != _vm_get_modules)
        return _vm_get_modules(modules,size);

    return (VMINT )-1;
}
