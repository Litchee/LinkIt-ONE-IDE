#include "vmsys.h"
#include "vmdes.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 * (*_vm_des_decrypt_t)( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len );
_vm_des_decrypt_t _vm_des_decrypt = NULL;

VMUINT8 * vm_des_decrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
    if (NULL == _vm_des_decrypt)
        _vm_des_decrypt = (_vm_des_decrypt_t)vm_get_sym_entry("vm_des_decrypt");

    if (NULL != _vm_des_decrypt)
        return _vm_des_decrypt(handle,input,input_len,output_len);

    return (VMUINT8 * )0;
}
