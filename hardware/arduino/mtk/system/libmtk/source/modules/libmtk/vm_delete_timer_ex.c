#include "vmsys.h"
#include "vmtimer.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_delete_timer_ex_t)(VMINT timerid);
_vm_delete_timer_ex_t _vm_delete_timer_ex = NULL;

VMINT vm_delete_timer_ex(VMINT timerid)
{
    if (NULL == _vm_delete_timer_ex)
        _vm_delete_timer_ex = (_vm_delete_timer_ex_t)vm_get_sym_entry("vm_delete_timer_ex");

    if (NULL != _vm_delete_timer_ex)
        return _vm_delete_timer_ex(timerid);

    return (VMINT )-1;
}
