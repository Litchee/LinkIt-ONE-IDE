#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_set_client_auth_t)(VMINT res_id, vm_tls_auth_mode_enum modes[], VMINT num);
_vm_tls_set_client_auth_t _vm_tls_set_client_auth = NULL;

VMINT vm_tls_set_client_auth(VMINT res_id, vm_tls_auth_mode_enum modes[], VMINT num)
{
    if (NULL == _vm_tls_set_client_auth)
        _vm_tls_set_client_auth = (_vm_tls_set_client_auth_t)vm_get_sym_entry("vm_tls_set_client_auth");

    if (NULL != _vm_tls_set_client_auth)
        return _vm_tls_set_client_auth(res_id,modes,num);

    return (VMINT)-1;
}