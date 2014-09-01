#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_write_t)(VMINT handle, void* buf, VMINT len);
_vm_tcp_write_t _vm_tcp_write = NULL;

VMINT vm_tcp_write(VMINT handle, void* buf, VMINT len)
{
    if (NULL == _vm_tcp_write)
        _vm_tcp_write = (_vm_tcp_write_t)vm_get_sym_entry("vm_tcp_write");

    if (NULL != _vm_tcp_write)
        return _vm_tcp_write(handle,buf,len);

    return (VMINT )-1;
}
