#include "vmsys.h"
#include "vmtimer.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void  (*_vm_set_kal_timer_t)(vm_kal_timerid timer_ptr, vm_kal_timer_func_ptr handler_func_ptr,void *handler_param_ptr, VMUINT32 delay, VMUINT32 reshedule_time);
_vm_set_kal_timer_t _vm_set_kal_timer = NULL;
void vm_set_kal_timer(vm_kal_timerid timer_ptr, vm_kal_timer_func_ptr handler_func_ptr,void *handler_param_ptr, VMUINT32 delay, VMUINT32 reshedule_time)

{
    if (NULL == _vm_set_kal_timer)
        _vm_set_kal_timer = (_vm_set_kal_timer_t)vm_get_sym_entry("vm_set_kal_timer");
    if (NULL != _vm_set_kal_timer)
        _vm_set_kal_timer(timer_ptr,handler_func_ptr,handler_param_ptr,delay,reshedule_time);
}