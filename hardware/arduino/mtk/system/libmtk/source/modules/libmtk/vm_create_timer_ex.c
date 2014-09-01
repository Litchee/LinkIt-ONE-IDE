#include "vmsys.h"
#include "vmtimer.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_create_timer_ex_t)(VMUINT32 millisec, VM_TIMERPROC_T timerproc);
_vm_create_timer_ex_t _vm_create_timer_ex = NULL;

VMINT vm_create_timer_ex(VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
    if (NULL == _vm_create_timer_ex)
        _vm_create_timer_ex = (_vm_create_timer_ex_t)vm_get_sym_entry("vm_create_timer_ex");

    if (NULL != _vm_create_timer_ex)
        return _vm_create_timer_ex(millisec,timerproc);

    return (VMINT )-1;
}
