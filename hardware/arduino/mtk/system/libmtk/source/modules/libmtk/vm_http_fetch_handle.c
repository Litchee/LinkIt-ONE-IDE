#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_fetch_handle_t)(VMINT type, void* p);
_vm_http_fetch_handle_t _vm_http_fetch_handle = NULL;

VMINT vm_http_fetch_handle(VMINT type, void* p)
{
    if (NULL == _vm_http_fetch_handle)
        _vm_http_fetch_handle = (_vm_http_fetch_handle_t)vm_get_sym_entry("vm_http_fetch_handle");

    if (NULL != _vm_http_fetch_handle)
        return _vm_http_fetch_handle(type,p);

    return (VMINT )-1;
}
