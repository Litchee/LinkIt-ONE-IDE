#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_power_up_t)(VMUINT16 camere_id, vm_vdorec_callback callback);
_vm_vdorec_power_up_t _vm_vdorec_power_up = NULL;

VMINT vm_vdorec_power_up(VMUINT16 camere_id, vm_vdorec_callback callback)
{
    if (NULL == _vm_vdorec_power_up)
        _vm_vdorec_power_up = (_vm_vdorec_power_up_t)vm_get_sym_entry("vm_vdorec_power_up");

    if (NULL != _vm_vdorec_power_up)
        return _vm_vdorec_power_up(camere_id, callback);

    return (VMINT )-1;
}
