#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_power_down_t)(void);
_vm_vdorec_power_down_t _vm_vdorec_power_down = NULL;

VMINT vm_vdorec_power_down(void)
{
    if (NULL == _vm_vdorec_power_down)
        _vm_vdorec_power_down = (_vm_vdorec_power_down_t)vm_get_sym_entry("vm_vdorec_power_down");

    if (NULL != _vm_vdorec_power_down)
        return _vm_vdorec_power_down();

    return (VMINT )-1;
}
