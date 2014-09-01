#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_search_abort_t)(void);
_vm_btcm_search_abort_t _vm_btcm_search_abort = NULL;
VMINT vm_btcm_search_abort(void)
{
    if (NULL == _vm_btcm_search_abort)
        _vm_btcm_search_abort = (_vm_btcm_search_abort_t)vm_get_sym_entry("vm_btcm_search_abort");

    if (NULL != _vm_btcm_search_abort)
        return _vm_btcm_search_abort();

    return (VMINT)-1;
}
