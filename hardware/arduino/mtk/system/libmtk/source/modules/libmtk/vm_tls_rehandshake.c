#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_rehandshake_t)(VMINT res_id);
_vm_tls_rehandshake_t _vm_tls_rehandshake = NULL;

VMINT vm_tls_rehandshake(VMINT res_id)
{
    if (NULL == _vm_tls_rehandshake)
        _vm_tls_rehandshake = (_vm_tls_rehandshake_t)vm_get_sym_entry("vm_tls_rehandshake");

    if (NULL != _vm_tls_rehandshake)
        return _vm_tls_rehandshake(res_id);

    return (VMINT)-1;
}