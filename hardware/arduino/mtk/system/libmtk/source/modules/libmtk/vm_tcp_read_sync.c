#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_read_sync_t)(VMINT handle, void* buf, VMINT len);
_vm_tcp_read_sync_t _vm_tcp_read_sync = NULL;

VMINT vm_tcp_read_sync(VMINT handle, void* buf, VMINT len)
{
    if (NULL == _vm_tcp_read_sync)
        _vm_tcp_read_sync = (_vm_tcp_read_sync_t)vm_get_sym_entry("vm_tcp_read_sync");
    if (NULL != _vm_tcp_read_sync)
        return _vm_tcp_read_sync(handle,buf,len);
    return (VMINT)-1;
}