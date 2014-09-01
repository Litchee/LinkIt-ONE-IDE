#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_get_cipher_t)(VMINT res_id, vm_tls_ciphersuites_enum *cipher);
_vm_tls_get_cipher_t _vm_tls_get_cipher = NULL;

VMINT vm_tls_get_cipher(VMINT res_id, vm_tls_ciphersuites_enum *cipher)
{
    if (NULL == _vm_tls_get_cipher)
        _vm_tls_get_cipher = (_vm_tls_get_cipher_t)vm_get_sym_entry("vm_tls_get_cipher");

    if (NULL != _vm_tls_get_cipher)
        return _vm_tls_get_cipher(res_id,cipher);

    return (VMINT)-1;
}