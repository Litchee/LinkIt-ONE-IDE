#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_connect_sync_t)(const char* ip, const VMINT port, VMINT apn);
_vm_tcp_connect_sync_t _vm_tcp_connect_sync = NULL;

VMINT vm_tcp_connect_sync(const char* ip, const VMINT port, VMINT apn)
{
    if (NULL == _vm_tcp_connect_sync)
        _vm_tcp_connect_sync = (_vm_tcp_connect_sync_t)vm_get_sym_entry("vm_tcp_connect_sync");
    if (NULL != _vm_tcp_connect_sync)
        return _vm_tcp_connect_sync(ip,port,apn);
    return (VMINT)-1;
}