#include "vmsys.h"
#include "vmdes.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_des_reset_key_t)( VMDESHANDLE handle );
_vm_des_reset_key_t _vm_des_reset_key = NULL;

VMINT vm_des_reset_key( VMDESHANDLE handle )
{
    if (NULL == _vm_des_reset_key)
        _vm_des_reset_key = (_vm_des_reset_key_t)vm_get_sym_entry("vm_des_reset_key");

    if (NULL != _vm_des_reset_key)
        return _vm_des_reset_key(handle);

    return (VMINT )-1;
}
