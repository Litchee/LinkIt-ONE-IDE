#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_phb_get_group_list_count_t)(void);
_vm_phb_get_group_list_count_t _vm_phb_get_group_list_count = NULL;

VMINT vm_phb_get_group_list_count(void)
{
    if (NULL == _vm_phb_get_group_list_count)
        _vm_phb_get_group_list_count = (_vm_phb_get_group_list_count_t)vm_get_sym_entry("vm_phb_get_group_list_count");

    if (NULL != _vm_phb_get_group_list_count)
        return _vm_phb_get_group_list_count();

    return (VMINT )-1;
}
