#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_vibrator_once_t)(void);
_vm_vibrator_once_t _vm_vibrator_once = NULL;

void vm_vibrator_once(void)
{
    if (NULL == _vm_vibrator_once)
        _vm_vibrator_once = (_vm_vibrator_once_t)vm_get_sym_entry("vm_vibrator_once");

    if (NULL != _vm_vibrator_once)
        _vm_vibrator_once();

    
}
