#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_set_ciphers_t)(VMINT res_id, const vm_tls_cipher_enum ciphers[], VMINT num);
_vm_tls_set_ciphers_t _vm_tls_set_ciphers = NULL;

VMINT vm_tls_set_ciphers(VMINT res_id, const vm_tls_cipher_enum ciphers[], VMINT num)
{
    if (NULL == _vm_tls_set_ciphers)
        _vm_tls_set_ciphers = (_vm_tls_set_ciphers_t)vm_get_sym_entry("vm_tls_set_ciphers");

    if (NULL != _vm_tls_set_ciphers)
        return _vm_tls_set_ciphers(res_id,ciphers,num);

    return (VMINT)-1;
}