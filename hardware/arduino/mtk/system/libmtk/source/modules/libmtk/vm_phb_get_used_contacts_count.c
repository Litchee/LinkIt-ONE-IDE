#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_phb_get_used_contacts_count_t)(vm_phb_storage_loc_enum storage);
_vm_phb_get_used_contacts_count_t _vm_phb_get_used_contacts_count = NULL;

VMINT vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage)
{
    if (NULL == _vm_phb_get_used_contacts_count)
        _vm_phb_get_used_contacts_count = (_vm_phb_get_used_contacts_count_t)vm_get_sym_entry("vm_phb_get_used_contacts_count");

    if (NULL != _vm_phb_get_used_contacts_count)
        return _vm_phb_get_used_contacts_count(storage);

    return (VMINT )-1;
}
