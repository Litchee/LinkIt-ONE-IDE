#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_read_t)(VMINT handle, void* buf, VMINT len);
_vm_tcp_read_t _vm_tcp_read = NULL;

VMINT vm_tcp_read(VMINT handle, void* buf, VMINT len)
{
    if (NULL == _vm_tcp_read)
        _vm_tcp_read = (_vm_tcp_read_t)vm_get_sym_entry("vm_tcp_read");

    if (NULL != _vm_tcp_read)
        return _vm_tcp_read(handle,buf,len);

    return (VMINT )-1;
}
