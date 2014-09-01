#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_callout_t)(VMWSTR phnum);
_vm_callout_t _vm_callout = NULL;

void vm_callout(VMWSTR phnum)
{
    if (NULL == _vm_callout)
        _vm_callout = (_vm_callout_t)vm_get_sym_entry("vm_callout");

    if (NULL != _vm_callout)
        _vm_callout(phnum);

    
}
