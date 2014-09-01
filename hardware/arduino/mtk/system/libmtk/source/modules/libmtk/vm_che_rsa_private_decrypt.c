#include "vmsys.h"
#include "vmche.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_che_rsa_private_decrypt_t)(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding);
_vm_che_rsa_private_decrypt_t _vm_che_rsa_private_decrypt = NULL;

VMINT vm_che_rsa_private_decrypt(vm_stche *ctx, VMUINT8 *src, VMUINT src_len, VMUINT8 *dst, 
										VMUINT *dst_len, vm_che_rsa_padding_mode_enum padding)
{
    if (NULL == _vm_che_rsa_private_decrypt)
        _vm_che_rsa_private_decrypt = (_vm_che_rsa_private_decrypt_t)vm_get_sym_entry("vm_che_rsa_private_decrypt");

    if (NULL != _vm_che_rsa_private_decrypt)
        return _vm_che_rsa_private_decrypt(ctx,src,src_len,dst,dst_len,padding);

    return (VMINT )-1;
}
