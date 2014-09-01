#include "vmsys.h"
#include "vmpwr.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_fly_mode_switch_t)(VMBOOL flight_mode_on, VMBOOL check_sim, vm_fly_mode_cb cb, void *user_data);
_vm_fly_mode_switch_t _vm_fly_mode_switch = NULL;

VMBOOL vm_fly_mode_switch(VMBOOL flight_mode_on, VMBOOL check_sim, vm_fly_mode_cb cb, void *user_data)
{
    if (NULL == _vm_fly_mode_switch)
        _vm_fly_mode_switch = (_vm_fly_mode_switch_t)vm_get_sym_entry("vm_fly_mode_switch");

    if (NULL != _vm_fly_mode_switch)
        return _vm_fly_mode_switch(flight_mode_on, check_sim, cb, user_data);

    return (VMBOOL)-1;
}