#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_peek_stack_t)(VMINT stackHandle, void** ptr);
_vm_peek_stack_t _vm_peek_stack = NULL;

VMINT vm_peek_stack(VMINT stackHandle, void** ptr)
{
    if (NULL == _vm_peek_stack)
        _vm_peek_stack = (_vm_peek_stack_t)vm_get_sym_entry("vm_peek_stack");

    if (NULL != _vm_peek_stack)
        return _vm_peek_stack(stackHandle,ptr);

    return (VMINT )-1;
}
