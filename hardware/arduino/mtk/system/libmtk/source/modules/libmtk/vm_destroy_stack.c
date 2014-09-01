#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_destroy_stack_t)(VMINT stackHandle);
_vm_destroy_stack_t _vm_destroy_stack = NULL;

VMINT vm_destroy_stack(VMINT stackHandle)
{
    if (NULL == _vm_destroy_stack)
        _vm_destroy_stack = (_vm_destroy_stack_t)vm_get_sym_entry("vm_destroy_stack");

    if (NULL != _vm_destroy_stack)
        return _vm_destroy_stack(stackHandle);

    return (VMINT )-1;
}
