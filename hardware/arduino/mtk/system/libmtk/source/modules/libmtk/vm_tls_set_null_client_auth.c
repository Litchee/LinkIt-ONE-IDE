#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_set_null_client_auth_t)(VMINT res_id);
_vm_tls_set_null_client_auth_t _vm_tls_set_null_client_auth = NULL;

VMINT vm_tls_set_null_client_auth(VMINT res_id)
{
    if (NULL == _vm_tls_set_null_client_auth)
        _vm_tls_set_null_client_auth = (_vm_tls_set_null_client_auth_t)vm_get_sym_entry("vm_tls_set_null_client_auth");

    if (NULL != _vm_tls_set_null_client_auth)
        return _vm_tls_set_null_client_auth(res_id);

    return (VMINT)-1;
}