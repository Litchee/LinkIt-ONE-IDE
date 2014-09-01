#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_charbat_is_charging_t)(void) ;
_vm_charbat_is_charging_t _vm_charbat_is_charging = NULL;

VMBOOL vm_charbat_is_charging(void) 
{
    if (NULL == _vm_charbat_is_charging)
        _vm_charbat_is_charging = (_vm_charbat_is_charging_t)vm_get_sym_entry("vm_charbat_is_charging");

    if (NULL != _vm_charbat_is_charging)
        return _vm_charbat_is_charging();

    return VM_FALSE;
}
