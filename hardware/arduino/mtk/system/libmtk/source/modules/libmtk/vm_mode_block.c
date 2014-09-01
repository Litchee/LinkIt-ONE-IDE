#include "vmsys.h"
#include "vmpwr.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_mode_block_t)(void);
_vm_mode_block_t _vm_mode_block = NULL;
void vm_mode_block(void)
{
    if (NULL == _vm_mode_block)
        _vm_mode_block = (_vm_mode_block_t)vm_get_sym_entry("vm_mode_block");

    if (NULL != _vm_mode_block)
        _vm_mode_block();
}

