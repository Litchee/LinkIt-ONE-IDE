#include "vmsys.h"
#include "vmtimer.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_create_timer_t)(VMUINT32 millisec, VM_TIMERPROC_T timerproc);
_vm_create_timer_t _vm_create_timer = NULL;

VMINT vm_create_timer(VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
    if (NULL == _vm_create_timer)
        _vm_create_timer = (_vm_create_timer_t)vm_get_sym_entry("vm_create_timer");

    if (NULL != _vm_create_timer)
        return _vm_create_timer(millisec,timerproc);

    return (VMINT )-1;
}
