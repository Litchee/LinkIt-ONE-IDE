#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_create_linked_stack_t)(VMINT capability, VMINT* handle);
_vm_create_linked_stack_t _vm_create_linked_stack = NULL;

VMINT vm_create_linked_stack(VMINT capability, VMINT* handle)
{
    if (NULL == _vm_create_linked_stack)
        _vm_create_linked_stack = (_vm_create_linked_stack_t)vm_get_sym_entry("vm_create_linked_stack");

    if (NULL != _vm_create_linked_stack)
        return _vm_create_linked_stack(capability,handle);

    return (VMINT )-1;
}
