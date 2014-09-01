#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_handshake_t)(VMINT res_id);
_vm_tls_handshake_t _vm_tls_handshake = NULL;

VMINT vm_tls_handshake(VMINT res_id)
{
    if (NULL == _vm_tls_handshake)
        _vm_tls_handshake = (_vm_tls_handshake_t)vm_get_sym_entry("vm_tls_handshake");

    if (NULL != _vm_tls_handshake)
        return _vm_tls_handshake(res_id);

    return (VMINT)-1;
}