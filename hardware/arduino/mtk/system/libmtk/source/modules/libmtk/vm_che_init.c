#include "vmsys.h"
#include "vmche.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_che_init_t)(vm_stche *che_context_p, VMUINT type);
_vm_che_init_t _vm_che_init = NULL;

void vm_che_init(vm_stche *che_context_p, VMUINT type)
{
    if (NULL == _vm_che_init)
        _vm_che_init = (_vm_che_init_t)vm_get_sym_entry("vm_che_init");

    if (NULL != _vm_che_init)
        _vm_che_init(che_context_p,type);
}
