#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_new_ctx_t)(vm_tls_version_enum ver, vm_socket_type_enum sock_type, VMINT apn, vm_tls_side_enum side, callback_t cb);
_vm_tls_new_ctx_t _vm_tls_new_ctx = NULL;

VMINT vm_tls_new_ctx(vm_tls_version_enum ver, vm_socket_type_enum sock_type, VMINT apn, vm_tls_side_enum side, callback_t cb)
{
    if (NULL == _vm_tls_new_ctx)
        _vm_tls_new_ctx = (_vm_tls_new_ctx_t)vm_get_sym_entry("vm_tls_new_ctx");

    if (NULL != _vm_tls_new_ctx)
        return _vm_tls_new_ctx(ver,sock_type, apn, side,cb);

    return (VMINT)-1;
}