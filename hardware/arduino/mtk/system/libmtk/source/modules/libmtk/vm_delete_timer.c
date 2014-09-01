#include "vmsys.h"
#include "vmtimer.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_delete_timer_t)(VMINT timerid);
_vm_delete_timer_t _vm_delete_timer = NULL;

VMINT vm_delete_timer(VMINT timerid)
{
    if (NULL == _vm_delete_timer)
        _vm_delete_timer = (_vm_delete_timer_t)vm_get_sym_entry("vm_delete_timer");

    if (NULL != _vm_delete_timer)
        return _vm_delete_timer(timerid);

    return (VMINT )-1;
}
