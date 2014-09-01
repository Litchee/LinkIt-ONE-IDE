#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_phb_get_group_name_by_id_t)(VMUINT group_id, VMWCHAR *group_name, VMINT len);
_vm_phb_get_group_name_by_id_t _vm_phb_get_group_name_by_id = NULL;

VMINT vm_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR *group_name, VMINT len)
{
    if (NULL == _vm_phb_get_group_name_by_id)
        _vm_phb_get_group_name_by_id = (_vm_phb_get_group_name_by_id_t)vm_get_sym_entry("vm_phb_get_group_name_by_id");

    if (NULL != _vm_phb_get_group_name_by_id)
        return _vm_phb_get_group_name_by_id(group_id,group_name,len);

    return (VMINT )-1;
}
