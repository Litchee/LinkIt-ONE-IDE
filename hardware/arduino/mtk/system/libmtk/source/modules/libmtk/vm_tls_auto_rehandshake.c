#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_auto_rehandshake_t)(VMINT res_id, VMINT onoff);
_vm_tls_auto_rehandshake_t _vm_tls_auto_rehandshake = NULL;

VMINT vm_tls_auto_rehandshake(VMINT res_id, VMINT onoff)
{
    if (NULL == _vm_tls_auto_rehandshake)
        _vm_tls_auto_rehandshake = (_vm_tls_auto_rehandshake_t)vm_get_sym_entry("vm_tls_auto_rehandshake");

    if (NULL != _vm_tls_auto_rehandshake)
        return _vm_tls_auto_rehandshake(res_id,onoff);

    return (VMINT)-1;
}