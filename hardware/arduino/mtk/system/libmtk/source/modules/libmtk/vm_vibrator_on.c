#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_vibrator_on_t)(void);
_vm_vibrator_on_t _vm_vibrator_on = NULL;

void vm_vibrator_on(void)
{
    if (NULL == _vm_vibrator_on)
        _vm_vibrator_on = (_vm_vibrator_on_t)vm_get_sym_entry("vm_vibrator_on");

    if (NULL != _vm_vibrator_on)
        _vm_vibrator_on();

    
}
