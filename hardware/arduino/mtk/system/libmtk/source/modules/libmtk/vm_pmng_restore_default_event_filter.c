#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_restore_default_event_filter_t)(void);
_vm_pmng_restore_default_event_filter_t _vm_pmng_restore_default_event_filter = NULL;

VMINT vm_pmng_restore_default_event_filter(void)
{
    if (NULL == _vm_pmng_restore_default_event_filter)
        _vm_pmng_restore_default_event_filter = (_vm_pmng_restore_default_event_filter_t)vm_get_sym_entry("vm_pmng_restore_default_event_filter");

    if (NULL != _vm_pmng_restore_default_event_filter)
        return _vm_pmng_restore_default_event_filter();

    return -1;
}
