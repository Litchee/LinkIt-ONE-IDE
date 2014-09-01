#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_set_body_t)(VMINT handle, VMUINT8* data, VMINT len);
_vm_http_set_body_t _vm_http_set_body = NULL;

VMINT vm_http_set_body(VMINT handle, VMUINT8* data, VMINT len)
{
    if (NULL == _vm_http_set_body)
        _vm_http_set_body = (_vm_http_set_body_t)vm_get_sym_entry("vm_http_set_body");

    if (NULL != _vm_http_set_body)
        return _vm_http_set_body(handle,data,len);

    return (VMINT )-1;
}
