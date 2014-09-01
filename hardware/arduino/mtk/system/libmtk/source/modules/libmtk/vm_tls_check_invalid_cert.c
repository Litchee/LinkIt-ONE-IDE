#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_check_invalid_cert_t)(VMINT res_id, VMINT onoff);
_vm_tls_check_invalid_cert_t _vm_tls_check_invalid_cert = NULL;

VMINT vm_tls_check_invalid_cert(VMINT res_id, VMINT onoff)
{
    if (NULL == _vm_tls_check_invalid_cert)
        _vm_tls_check_invalid_cert = (_vm_tls_check_invalid_cert_t)vm_get_sym_entry("vm_tls_check_invalid_cert");

    if (NULL != _vm_tls_check_invalid_cert)
        return _vm_tls_check_invalid_cert(res_id,onoff);

    return (VMINT)-1;
}