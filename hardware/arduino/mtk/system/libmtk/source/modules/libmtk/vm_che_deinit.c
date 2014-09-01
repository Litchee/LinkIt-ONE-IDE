#include "vmsys.h"
#include "vmche.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_che_deinit_t)(vm_stche *che_context_p );
_vm_che_deinit_t _vm_che_deinit = NULL;

void vm_che_deinit(vm_stche *che_context_p)
{
    if (NULL == _vm_che_deinit)
        _vm_che_deinit = (_vm_che_deinit_t)vm_get_sym_entry("vm_che_deinit");

    if (NULL != _vm_che_deinit)
        _vm_che_deinit(che_context_p);

}
