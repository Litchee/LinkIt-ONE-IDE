#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_reset_stack_t)(VMINT stackHandle);
_vm_reset_stack_t _vm_reset_stack = NULL;

VMINT vm_reset_stack(VMINT stackHandle)
{
    if (NULL == _vm_reset_stack)
        _vm_reset_stack = (_vm_reset_stack_t)vm_get_sym_entry("vm_reset_stack");

    if (NULL != _vm_reset_stack)
        return _vm_reset_stack(stackHandle);

    return (VMINT )-1;
}
