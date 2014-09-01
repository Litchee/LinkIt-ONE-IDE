#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_delete_ctx_t)(VMINT res_id);
_vm_tls_delete_ctx_t _vm_tls_delete_ctx = NULL;

VMINT vm_tls_delete_ctx(VMINT res_id)
{
    if (NULL == _vm_tls_delete_ctx)
        _vm_tls_delete_ctx = (_vm_tls_delete_ctx_t)vm_get_sym_entry("vm_tls_delete_ctx");

    if (NULL != _vm_tls_delete_ctx)
        return _vm_tls_delete_ctx(res_id);

    return (VMINT)-1;
}