#include "vmsys.h"
#include "vmcontact.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_phb_search_contact_list_t)( vm_phb_search_list_req_struct *req_info, vm_phb_contact_pos_struct *pos_array, VMINT post_array_len);
_vm_phb_search_contact_list_t _vm_phb_search_contact_list = NULL;

VMINT vm_phb_search_contact_list( vm_phb_search_list_req_struct *req_info, vm_phb_contact_pos_struct *pos_array, VMINT post_array_len)
{
    if (NULL == _vm_phb_search_contact_list)
        _vm_phb_search_contact_list = (_vm_phb_search_contact_list_t)vm_get_sym_entry("vm_phb_search_contact_list");

    if (NULL != _vm_phb_search_contact_list)
        return _vm_phb_search_contact_list(req_info,pos_array,post_array_len);

    return (VMINT )-1;
}
