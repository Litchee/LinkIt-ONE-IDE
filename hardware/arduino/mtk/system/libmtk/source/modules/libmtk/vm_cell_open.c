#include "vmsys.h"
#include "vmcell.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_cell_open_t)(void);
_vm_cell_open_t _vm_cell_open = NULL;

VMINT vm_cell_open(void)
{
    if (NULL == _vm_cell_open)
        _vm_cell_open = (_vm_cell_open_t)vm_get_sym_entry("vm_cell_open");

    if (NULL != _vm_cell_open)
        return _vm_cell_open();

    return (VMINT )-1;
}
