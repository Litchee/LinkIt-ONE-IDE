#include "vmsys.h"
#include "vmpwr.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_fly_mode_is_switching_t)(void);
_vm_fly_mode_is_switching_t _vm_fly_mode_is_switching = NULL;

VMBOOL vm_fly_mode_is_switching(void)
{
    if (NULL == _vm_fly_mode_is_switching)
        _vm_fly_mode_is_switching = (_vm_fly_mode_is_switching_t)vm_get_sym_entry("vm_fly_mode_is_switching");

    if (NULL != _vm_fly_mode_is_switching)
        return _vm_fly_mode_is_switching();

    return (VMBOOL)-1;
}