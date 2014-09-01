#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_tick_count_t)(void);
_vm_get_tick_count_t _vm_get_tick_count = NULL;

VMINT vm_get_tick_count(void)
{
    if (NULL == _vm_get_tick_count)
        _vm_get_tick_count = (_vm_get_tick_count_t)vm_get_sym_entry("vm_get_tick_count");

    if (NULL != _vm_get_tick_count)
        return _vm_get_tick_count();

    return (VMINT )-1;
}
