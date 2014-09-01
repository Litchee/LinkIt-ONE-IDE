#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_connect_ex_t)(const char* host, const VMINT port, const VMINT apn, void *user_data, void (*callback)(VMINT handle, VMINT event, void *user_data));
_vm_tcp_connect_ex_t _vm_tcp_connect_ex = NULL;

VMINT vm_tcp_connect_ex(const char* host, const VMINT port, const VMINT apn, void *user_data, void (*callback)(VMINT handle, VMINT event, void *user_data))
{
    if (NULL == _vm_tcp_connect_ex)
        _vm_tcp_connect_ex = (_vm_tcp_connect_ex_t)vm_get_sym_entry("vm_tcp_connect_ex");

    if (NULL != _vm_tcp_connect_ex)
        return _vm_tcp_connect_ex(host,port,apn, user_data, callback);

    return (VMINT )-1;
}
