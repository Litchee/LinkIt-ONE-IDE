#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_http_request_t)(http_request_t *request, http_session_t *session);
_vm_http_request_t _vm_http_request = NULL;

int vm_http_request(http_request_t *request, http_session_t *session)
{
    int  ret = {-1};
    if (NULL == _vm_http_request)
        _vm_http_request = (_vm_http_request_t)vm_get_sym_entry("vm_http_request");

    if (NULL != _vm_http_request)
        return _vm_http_request(request,session);

    return ret;
}
