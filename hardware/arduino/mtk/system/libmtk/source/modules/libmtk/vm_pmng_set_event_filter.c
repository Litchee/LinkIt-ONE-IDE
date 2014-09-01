#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_set_event_filter_t)(_event_filter_t* be_filter);
_vm_pmng_set_event_filter_t _vm_pmng_set_event_filter = NULL;

VMINT vm_pmng_set_event_filter(_event_filter_t* be_filter)
{
    if (NULL == _vm_pmng_set_event_filter)
        _vm_pmng_set_event_filter = (_vm_pmng_set_event_filter_t)vm_get_sym_entry("vm_pmng_set_event_filter");

    if (NULL != _vm_pmng_set_event_filter)
        return _vm_pmng_set_event_filter(be_filter);

    return -1;
}
