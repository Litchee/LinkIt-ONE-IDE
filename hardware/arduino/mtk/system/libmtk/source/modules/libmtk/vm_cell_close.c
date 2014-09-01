#include "vmsys.h"
#include "vmcell.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_cell_close_t)(void);
_vm_cell_close_t _vm_cell_close = NULL;

void vm_cell_close(void)
{
    if (NULL == _vm_cell_close)
        _vm_cell_close = (_vm_cell_close_t)vm_get_sym_entry("vm_cell_close");

    if (NULL != _vm_cell_close)
        _vm_cell_close();

    
}
