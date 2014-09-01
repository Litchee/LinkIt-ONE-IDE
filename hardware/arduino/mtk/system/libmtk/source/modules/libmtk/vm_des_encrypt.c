#include "vmsys.h"
#include "vmdes.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 * (*_vm_des_encrypt_t)( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len );
_vm_des_encrypt_t _vm_des_encrypt = NULL;

VMUINT8 * vm_des_encrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
    if (NULL == _vm_des_encrypt)
        _vm_des_encrypt = (_vm_des_encrypt_t)vm_get_sym_entry("vm_des_encrypt");

    if (NULL != _vm_des_encrypt)
        return _vm_des_encrypt(handle,input,input_len,output_len);

    return (VMUINT8 * )0;
}
