#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_connect_t)(const char* host, const VMINT port, const VMINT apn, void (*callback)(VMINT handle, VMINT event));
_vm_tcp_connect_t _vm_tcp_connect = NULL;

VMINT vm_tcp_connect(const char* host, const VMINT port, const VMINT apn, void (*callback)(VMINT handle, VMINT event))
{
    if (NULL == _vm_tcp_connect)
        _vm_tcp_connect = (_vm_tcp_connect_t)vm_get_sym_entry("vm_tcp_connect");

    if (NULL != _vm_tcp_connect)
        return _vm_tcp_connect(host,port,apn,callback);

    return (VMINT )-1;
}
