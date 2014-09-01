#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_callout_ex_t)(VMWSTR phnum, VM_CALLOUT_RESPONSE_T callback);
_vm_callout_ex_t _vm_callout_ex = NULL;

VMINT vm_callout_ex(VMWSTR phnum, VM_CALLOUT_RESPONSE_T callback)
{
    if (NULL == _vm_callout_ex)
        _vm_callout_ex = (_vm_callout_ex_t)vm_get_sym_entry("vm_callout_ex");

    if (NULL != _vm_callout_ex)
        return _vm_callout_ex(phnum,callback);

    return (VMINT )-1;
}
