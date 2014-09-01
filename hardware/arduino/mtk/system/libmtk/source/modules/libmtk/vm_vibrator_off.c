#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_vibrator_off_t)(void);
_vm_vibrator_off_t _vm_vibrator_off = NULL;

void vm_vibrator_off(void)
{
    if (NULL == _vm_vibrator_off)
        _vm_vibrator_off = (_vm_vibrator_off_t)vm_get_sym_entry("vm_vibrator_off");

    if (NULL != _vm_vibrator_off)
        _vm_vibrator_off();

    
}
