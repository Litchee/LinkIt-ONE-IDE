#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_set_url_t)(VMINT handle, VMCHAR* url, VMINT len);
_vm_http_set_url_t _vm_http_set_url = NULL;

VMINT vm_http_set_url(VMINT handle, VMCHAR* url, VMINT len)
{
    if (NULL == _vm_http_set_url)
        _vm_http_set_url = (_vm_http_set_url_t)vm_get_sym_entry("vm_http_set_url");

    if (NULL != _vm_http_set_url)
        return _vm_http_set_url(handle,url,len);

    return (VMINT )-1;
}
