#include "vmsys.h"
#include "vmtimer.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void  (*_vm_cancel_kal_timer_t)(vm_kal_timerid timer_ptr);
_vm_cancel_kal_timer_t _vm_cancel_kal_timer = NULL;
void vm_cancel_kal_timer(vm_kal_timerid timer_ptr)

{
    if (NULL == _vm_cancel_kal_timer)
        _vm_cancel_kal_timer = (_vm_cancel_kal_timer_t)vm_get_sym_entry("vm_cancel_kal_timer");
    if (NULL != _vm_cancel_kal_timer)
        _vm_cancel_kal_timer(timer_ptr);
}