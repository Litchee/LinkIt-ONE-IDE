#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_cancel_asyn_http_req_t)(VMINT handle);
_vm_cancel_asyn_http_req_t _vm_cancel_asyn_http_req = NULL;

VMINT vm_cancel_asyn_http_req(VMINT handle)
{
    if (NULL == _vm_cancel_asyn_http_req)
        _vm_cancel_asyn_http_req = (_vm_cancel_asyn_http_req_t)vm_get_sym_entry("vm_cancel_asyn_http_req");

    if (NULL != _vm_cancel_asyn_http_req)
        return _vm_cancel_asyn_http_req(handle);

    return (VMINT )-1;
}
