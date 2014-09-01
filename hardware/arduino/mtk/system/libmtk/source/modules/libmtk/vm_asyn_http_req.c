#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_asyn_http_req_t)(asyn_http_req_t *request, void (*http_hook)(VMINT, void*), void (*http_state_notify)(VMINT state, VMINT param, void* session));
_vm_asyn_http_req_t _vm_asyn_http_req = NULL;

VMINT vm_asyn_http_req(asyn_http_req_t *request, void (*http_hook)(VMINT, void*), void (*http_state_notify)(VMINT state, VMINT param, void* session))
{
    if (NULL == _vm_asyn_http_req)
        _vm_asyn_http_req = (_vm_asyn_http_req_t)vm_get_sym_entry("vm_asyn_http_req");

    if (NULL != _vm_asyn_http_req)
        return _vm_asyn_http_req(request,http_hook,http_state_notify);

    return (VMINT )-1;
}
