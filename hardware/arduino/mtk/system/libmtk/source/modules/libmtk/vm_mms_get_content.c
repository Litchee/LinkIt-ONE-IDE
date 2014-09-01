#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_get_content_t)(vm_mms_get_content_req_struct *req_data);
_vm_mms_get_content_t _vm_mms_get_content = NULL;

VMINT vm_mms_get_content(vm_mms_get_content_req_struct *req_data)
{
    if (NULL == _vm_mms_get_content)
        _vm_mms_get_content = (_vm_mms_get_content_t)vm_get_sym_entry("vm_mms_get_content");

    if (NULL != _vm_mms_get_content)
        return _vm_mms_get_content(req_data);

    return (VMINT)-1;
}

