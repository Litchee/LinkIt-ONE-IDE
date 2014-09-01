#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_mms_send_mms_t)(vm_send_mms_req_t * req_ptr, vm_mms_callback_type callback);
_vm_mms_send_mms_t _vm_mms_send_mms = NULL;

VMINT vm_mms_send_mms(vm_send_mms_req_t * req_ptr, vm_mms_callback_type callback)
{
    if (NULL == _vm_mms_send_mms)
        _vm_mms_send_mms = (_vm_mms_send_mms_t)vm_get_sym_entry("vm_mms_send_mms");

    if (NULL != _vm_mms_send_mms)
        return _vm_mms_send_mms(req_ptr,callback);

    return (VMINT )-1;
}
