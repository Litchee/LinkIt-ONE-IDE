#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_set_param_t)(VMUINT32 param_id, VMUINT16 value);
_vm_vdorec_set_param_t _vm_vdorec_set_param = NULL;

VMINT vm_vdorec_set_param(VMUINT32 param_id, VMUINT16 value)
{
    if (NULL == _vm_vdorec_set_param)
        _vm_vdorec_set_param = (_vm_vdorec_set_param_t)vm_get_sym_entry("vm_vdorec_set_param");

    if (NULL != _vm_vdorec_set_param)
        return _vm_vdorec_set_param(param_id, value);

    return (VMINT )-1;
}
