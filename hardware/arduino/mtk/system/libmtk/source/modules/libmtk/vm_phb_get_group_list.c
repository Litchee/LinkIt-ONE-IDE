#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_phb_get_group_list_t)(vm_phb_group_struct *group_array, VMINT group_array_len);
_vm_phb_get_group_list_t _vm_phb_get_group_list = NULL;

VMINT vm_phb_get_group_list(vm_phb_group_struct *group_array, VMINT group_array_len)
{
    if (NULL == _vm_phb_get_group_list)
        _vm_phb_get_group_list = (_vm_phb_get_group_list_t)vm_get_sym_entry("vm_phb_get_group_list");

    if (NULL != _vm_phb_get_group_list)
        return _vm_phb_get_group_list(group_array,group_array_len);

    return (VMINT )-1;
}
