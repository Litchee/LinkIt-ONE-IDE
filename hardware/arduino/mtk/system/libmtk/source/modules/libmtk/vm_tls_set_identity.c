#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_set_identity_t)(VMINT res_id, VMUINT32 cert_id);
_vm_tls_set_identity_t _vm_tls_set_identity = NULL;

VMINT vm_tls_set_identity(VMINT res_id, VMUINT32 cert_id)
{
    if (NULL == _vm_tls_set_identity)
        _vm_tls_set_identity = (_vm_tls_set_identity_t)vm_get_sym_entry("vm_tls_set_identity");

    if (NULL != _vm_tls_set_identity)
        return _vm_tls_set_identity(res_id,cert_id);

    return (VMINT)-1;
}