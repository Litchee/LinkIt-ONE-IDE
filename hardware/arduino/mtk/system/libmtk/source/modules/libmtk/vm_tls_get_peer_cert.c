#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_get_peer_cert_t)(VMINT res_id, vm_tls_cert_struct *cert);
_vm_tls_get_peer_cert_t _vm_tls_get_peer_cert = NULL;

VMINT vm_tls_get_peer_cert(VMINT res_id, vm_tls_cert_struct *cert)
{
    if (NULL == _vm_tls_get_peer_cert)
        _vm_tls_get_peer_cert = (_vm_tls_get_peer_cert_t)vm_get_sym_entry("vm_tls_get_peer_cert");

    if (NULL != _vm_tls_get_peer_cert)
        return _vm_tls_get_peer_cert(res_id,cert);

    return (VMINT)-1;
}