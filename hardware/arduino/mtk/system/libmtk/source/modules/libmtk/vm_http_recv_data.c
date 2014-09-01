#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_recv_data_t)(VMINT handle, VMUINT8* data, VMINT len);
_vm_http_recv_data_t _vm_http_recv_data = NULL;

VMINT vm_http_recv_data(VMINT handle, VMUINT8* data, VMINT len)
{
    if (NULL == _vm_http_recv_data)
        _vm_http_recv_data = (_vm_http_recv_data_t)vm_get_sym_entry("vm_http_recv_data");

    if (NULL != _vm_http_recv_data)
        return _vm_http_recv_data(handle,data,len);

    return (VMINT )-1;
}
