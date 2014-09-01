#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_asyn_http_req_handle_t)(asyn_http_req_t* request, VMINT* handle);
_vm_get_asyn_http_req_handle_t _vm_get_asyn_http_req_handle = NULL;

VMINT vm_get_asyn_http_req_handle(asyn_http_req_t* request, VMINT* handle)
{
    if (NULL == _vm_get_asyn_http_req_handle)
        _vm_get_asyn_http_req_handle = (_vm_get_asyn_http_req_handle_t)vm_get_sym_entry("vm_get_asyn_http_req_handle");

    if (NULL != _vm_get_asyn_http_req_handle)
        return _vm_get_asyn_http_req_handle(request,handle);

    return (VMINT )-1;
}
