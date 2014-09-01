#include "vmsys.h"
#include "vmdes.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMDESHANDLE (*_vm_des_set_key_t)( VMUINT8 key[8] );
_vm_des_set_key_t _vm_des_set_key = NULL;

VMDESHANDLE vm_des_set_key( VMUINT8 key[8] )
{
    VMDESHANDLE  ret = {-1};
    if (NULL == _vm_des_set_key)
        _vm_des_set_key = (_vm_des_set_key_t)vm_get_sym_entry("vm_des_set_key");

    if (NULL != _vm_des_set_key)
        return _vm_des_set_key(key);

    return ret;
}
