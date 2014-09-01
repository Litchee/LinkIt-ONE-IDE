#include "vmsys.h"
#include "vmcell.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_cell_info_struct** (*_vm_cell_get_nbr_cell_info_t)(void);
_vm_cell_get_nbr_cell_info_t _vm_cell_get_nbr_cell_info = NULL;

vm_cell_info_struct** vm_cell_get_nbr_cell_info(void)
{
    if (NULL == _vm_cell_get_nbr_cell_info)
        _vm_cell_get_nbr_cell_info = (_vm_cell_get_nbr_cell_info_t)vm_get_sym_entry("vm_cell_get_nbr_cell_info");

    if (NULL != _vm_cell_get_nbr_cell_info)
        return _vm_cell_get_nbr_cell_info();

    return (vm_cell_info_struct** )-1;
}
