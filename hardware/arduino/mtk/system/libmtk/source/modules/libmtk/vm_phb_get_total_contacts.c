#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_phb_get_total_contacts_t)(vm_phb_storage_loc_enum storage);
_vm_phb_get_total_contacts_t _vm_phb_get_total_contacts = NULL;

VMINT vm_phb_get_total_contacts(vm_phb_storage_loc_enum storage)
{
    if (NULL == _vm_phb_get_total_contacts)
        _vm_phb_get_total_contacts = (_vm_phb_get_total_contacts_t)vm_get_sym_entry("vm_phb_get_total_contacts");

    if (NULL != _vm_phb_get_total_contacts)
        return _vm_phb_get_total_contacts(storage);

    return (VMINT )-1;
}
