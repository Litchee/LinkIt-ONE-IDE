#include "vmsys.h"
#include "vmpwr.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void  (*_vm_switch_backlight_t)(VMINT turn_on);
_vm_switch_backlight_t _vm_switch_backlight = NULL;
void vm_switch_backlight(VMINT turn_on)
{
    if (NULL == _vm_switch_backlight)
        _vm_switch_backlight = (_vm_switch_backlight_t)vm_get_sym_entry("vm_switch_backlight");
    if (NULL != _vm_switch_backlight)
        _vm_switch_backlight(turn_on);
}
