#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_encoded_dtacct_id_t)(VMINT apn, VMUINT * dtacct_id);
_vm_get_encoded_dtacct_id_t _vm_get_encoded_dtacct_id = NULL;

VMINT vm_get_encoded_dtacct_id(VMINT apn, VMUINT * dtacct_id)
{
    if (NULL == _vm_get_encoded_dtacct_id)
        _vm_get_encoded_dtacct_id = (_vm_get_encoded_dtacct_id_t)vm_get_sym_entry("vm_get_encoded_dtacct_id");

    if (NULL != _vm_get_encoded_dtacct_id)
        return _vm_get_encoded_dtacct_id(apn,dtacct_id);

    return (VMINT )-1;
}
