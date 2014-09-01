#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_new_conn_t)(VMINT res_id, vm_sockaddr_ex_struct * faddr);
_vm_tls_new_conn_t _vm_tls_new_conn = NULL;

VMINT vm_tls_new_conn(VMINT res_id, vm_sockaddr_ex_struct * faddr)
{
    if (NULL == _vm_tls_new_conn)
        _vm_tls_new_conn = (_vm_tls_new_conn_t)vm_get_sym_entry("vm_tls_new_conn");

    if (NULL != _vm_tls_new_conn)
        return _vm_tls_new_conn(res_id,faddr);

    return (VMINT)-1;
}