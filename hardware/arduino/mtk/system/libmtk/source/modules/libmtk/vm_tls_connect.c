#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_connect_t)(VMINT res_id, vm_sockaddr_ex_struct * faddr);
_vm_tls_connect_t _vm_tls_connect = NULL;

VMINT vm_tls_connect(VMINT res_id, vm_sockaddr_ex_struct * faddr)
{
    if (NULL == _vm_tls_connect)
        _vm_tls_connect = (_vm_tls_connect_t)vm_get_sym_entry("vm_tls_connect");

    if (NULL != _vm_tls_connect)
        return _vm_tls_connect(res_id,faddr);

    return (VMINT)-1;
}