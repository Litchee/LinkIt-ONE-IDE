#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_close_sync_t)(VMINT handle);
_vm_tcp_close_sync_t _vm_tcp_close_sync = NULL;

VMINT vm_tcp_close_sync(VMINT handle)
{
    if (NULL == _vm_tcp_close_sync)
        _vm_tcp_close_sync = (_vm_tcp_close_sync_t)vm_get_sym_entry("vm_tcp_close_sync");
    if (NULL != _vm_tcp_close_sync)
        return _vm_tcp_close_sync(handle);
    return (VMINT)-1;
}