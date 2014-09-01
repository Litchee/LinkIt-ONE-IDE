#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_phb_req_error_enum (*_vm_phb_update_contact_t)(vm_phb_update_req_struct *req_info, vm_phb_callback_type cb);
_vm_phb_update_contact_t _vm_phb_update_contact = NULL;

vm_phb_req_error_enum vm_phb_update_contact(vm_phb_update_req_struct *req_info, vm_phb_callback_type cb)
{
    vm_phb_req_error_enum  ret = {-1};
    if (NULL == _vm_phb_update_contact)
        _vm_phb_update_contact = (_vm_phb_update_contact_t)vm_get_sym_entry("vm_phb_update_contact");

    if (NULL != _vm_phb_update_contact)
        return _vm_phb_update_contact(req_info,cb);

    return ret;
}
