#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_is_exist_stack_t)(VMINT stackHandle, void* ptr);
_vm_is_exist_stack_t _vm_is_exist_stack = NULL;

VMINT vm_is_exist_stack(VMINT stackHandle, void* ptr)
{
    if (NULL == _vm_is_exist_stack)
        _vm_is_exist_stack = (_vm_is_exist_stack_t)vm_get_sym_entry("vm_is_exist_stack");

    if (NULL != _vm_is_exist_stack)
        return _vm_is_exist_stack(stackHandle,ptr);

    return (VMINT )-1;
}
