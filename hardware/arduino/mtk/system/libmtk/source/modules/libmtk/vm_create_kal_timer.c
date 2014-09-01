#include "vmsys.h"
#include "vmtimer.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_kal_timerid (*_vm_create_kal_timer_t)(VMINT8 *timer_name);
_vm_create_kal_timer_t _vm_create_kal_timer = NULL;

vm_kal_timerid vm_create_kal_timer(VMINT8 *timer_name)
{
    if (NULL == _vm_create_kal_timer)
        _vm_create_kal_timer = (_vm_create_kal_timer_t)vm_get_sym_entry("vm_create_kal_timer");
    if (NULL != _vm_create_kal_timer)
        return _vm_create_kal_timer(timer_name);
    return (vm_kal_timerid)-1;
}