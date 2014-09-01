#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_phb_req_error_enum (*_vm_phb_search_contact_syn_t)(vm_phb_search_req_struct *req_info);
_vm_phb_search_contact_syn_t _vm_phb_search_contact_syn = NULL;

vm_phb_req_error_enum vm_phb_search_contact_syn(vm_phb_search_req_struct *req_info)
{
    vm_phb_req_error_enum  ret = {-1};
    if (NULL == _vm_phb_search_contact_syn)
        _vm_phb_search_contact_syn = (_vm_phb_search_contact_syn_t)vm_get_sym_entry("vm_phb_search_contact_syn");

    if (NULL != _vm_phb_search_contact_syn)
        return _vm_phb_search_contact_syn(req_info);

    return ret;
}
