#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_switch_power_saving_mode_t)(power_saving_mode_enum mode);
_vm_switch_power_saving_mode_t _vm_switch_power_saving_mode = NULL;

VMINT vm_switch_power_saving_mode(power_saving_mode_enum mode)
{
    if (NULL == _vm_switch_power_saving_mode)
        _vm_switch_power_saving_mode = (_vm_switch_power_saving_mode_t)vm_get_sym_entry("vm_switch_power_saving_mode");

    if (NULL != _vm_switch_power_saving_mode)
        return _vm_switch_power_saving_mode(mode);

    return (VMINT )-1;
}
