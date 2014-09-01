#include "vmsys.h"
#include "vmpwr.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_mode_unblock_t)(void);
_vm_mode_unblock_t _vm_mode_unblock = NULL;
void vm_mode_unblock(void)
{
    if (NULL == _vm_mode_unblock)
        _vm_mode_unblock = (_vm_mode_unblock_t)vm_get_sym_entry("vm_mode_unblock");

    if (NULL != _vm_mode_unblock)
        _vm_mode_unblock();
}

