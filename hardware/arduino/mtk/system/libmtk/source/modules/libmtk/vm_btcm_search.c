#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_search_t)(VMUINT8 max_response, VMUINT16 time_out, VMUINT cod, VMBYTE is_name_discovery);
_vm_btcm_search_t _vm_btcm_search = NULL;
VMINT vm_btcm_search(VMUINT8 max_response, VMUINT16 time_out, VMUINT cod, VMBYTE is_name_discovery)
{
    if (NULL == _vm_btcm_search)
        _vm_btcm_search = (_vm_btcm_search_t)vm_get_sym_entry("vm_btcm_search");

    if (NULL != _vm_btcm_search)
        return _vm_btcm_search(max_response,time_out,cod,is_name_discovery);

    return (VMINT)-1;
}
