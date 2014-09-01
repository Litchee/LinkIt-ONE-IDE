#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_delete_conn_t)(VMINT res_id);
_vm_tls_delete_conn_t _vm_tls_delete_conn = NULL;

VMINT vm_tls_delete_conn(VMINT res_id)
{
    if (NULL == _vm_tls_delete_conn)
        _vm_tls_delete_conn = (_vm_tls_delete_conn_t)vm_get_sym_entry("vm_tls_delete_conn");

    if (NULL != _vm_tls_delete_conn)
        return _vm_tls_delete_conn(res_id);

    return (VMINT)-1;
}