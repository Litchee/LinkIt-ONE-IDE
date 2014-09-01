#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_get_cipher_info_t)(VMINT res_id, vm_tls_cipher_info_struct *cipher_info);
_vm_tls_get_cipher_info_t _vm_tls_get_cipher_info = NULL;

VMINT vm_tls_get_cipher_info(VMINT res_id, vm_tls_cipher_info_struct *cipher_info)
{
    if (NULL == _vm_tls_get_cipher_info)
        _vm_tls_get_cipher_info = (_vm_tls_get_cipher_info_t)vm_get_sym_entry("vm_tls_get_cipher_info");

    if (NULL != _vm_tls_get_cipher_info)
        return _vm_tls_get_cipher_info(res_id,cipher_info);

    return (VMINT)-1;
}