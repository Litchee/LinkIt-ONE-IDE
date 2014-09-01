#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_shutdown_t)(VMINT res_id);
_vm_tls_shutdown_t _vm_tls_shutdown = NULL;

VMINT vm_tls_shutdown(VMINT res_id)
{
    if (NULL == _vm_tls_shutdown)
        _vm_tls_shutdown = (_vm_tls_shutdown_t)vm_get_sym_entry("vm_tls_shutdown");

    if (NULL != _vm_tls_shutdown)
        return _vm_tls_shutdown(res_id);

    return (VMINT)-1;
}