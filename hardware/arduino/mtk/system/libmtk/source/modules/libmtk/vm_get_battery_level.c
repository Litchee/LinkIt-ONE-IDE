#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_battery_level_t)(void) ;
_vm_get_battery_level_t _vm_get_battery_level = NULL;

VMINT vm_get_battery_level(void) 
{
    if (NULL == _vm_get_battery_level)
        _vm_get_battery_level = (_vm_get_battery_level_t)vm_get_sym_entry("vm_get_battery_level");

    if (NULL != _vm_get_battery_level)
        return _vm_get_battery_level();

    return (VMINT )-1;
}
