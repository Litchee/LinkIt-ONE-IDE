#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_check_peer_name_t)(VMINT res_id, const VMCHAR *const name);
_vm_tls_check_peer_name_t _vm_tls_check_peer_name = NULL;

VMINT vm_tls_check_peer_name(VMINT res_id, const VMCHAR *const name)
{
    if (NULL == _vm_tls_check_peer_name)
        _vm_tls_check_peer_name = (_vm_tls_check_peer_name_t)vm_get_sym_entry("vm_tls_check_peer_name");

    if (NULL != _vm_tls_check_peer_name)
        return _vm_tls_check_peer_name(res_id,name);

    return (VMINT)-1;
}