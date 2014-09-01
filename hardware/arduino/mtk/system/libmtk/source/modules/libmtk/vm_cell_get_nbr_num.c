#include "vmsys.h"
#include "vmcell.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT* (*_vm_cell_get_nbr_num_t)(void);
_vm_cell_get_nbr_num_t _vm_cell_get_nbr_num = NULL;

VMINT* vm_cell_get_nbr_num(void)
{
    if (NULL == _vm_cell_get_nbr_num)
        _vm_cell_get_nbr_num = (_vm_cell_get_nbr_num_t)vm_get_sym_entry("vm_cell_get_nbr_num");

    if (NULL != _vm_cell_get_nbr_num)
        return _vm_cell_get_nbr_num();

    return (VMINT* )-1;
}
