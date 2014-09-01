#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_push_stack_t)(VMINT stackHandle, void* ptr);
_vm_push_stack_t _vm_push_stack = NULL;

VMINT vm_push_stack(VMINT stackHandle, void* ptr)
{
    if (NULL == _vm_push_stack)
        _vm_push_stack = (_vm_push_stack_t)vm_get_sym_entry("vm_push_stack");

    if (NULL != _vm_push_stack)
        return _vm_push_stack(stackHandle,ptr);

    return (VMINT )-1;
}
