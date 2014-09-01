#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_add_header_t)(VMINT handle, VMCHAR* name, VMCHAR* value);
_vm_http_add_header_t _vm_http_add_header = NULL;

VMINT vm_http_add_header(VMINT handle, VMCHAR* name, VMCHAR* value)
{
    if (NULL == _vm_http_add_header)
        _vm_http_add_header = (_vm_http_add_header_t)vm_get_sym_entry("vm_http_add_header");

    if (NULL != _vm_http_add_header)
        return _vm_http_add_header(handle,name,value);

    return (VMINT )-1;
}
