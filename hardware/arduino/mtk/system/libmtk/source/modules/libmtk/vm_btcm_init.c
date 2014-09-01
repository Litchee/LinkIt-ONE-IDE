#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_init_t)(void (*callback)(VMUINT evt, void * param, void * user_data), VMUINT evt_mask, void * user_data);
_vm_btcm_init_t _vm_btcm_init = NULL;
VMINT vm_btcm_init(void (*callback)(VMUINT evt, void * param, void * user_data), VMUINT evt_mask, void * user_data)
{
    if (NULL == _vm_btcm_init)
        _vm_btcm_init = (_vm_btcm_init_t)vm_get_sym_entry("vm_btcm_init");

    if (NULL != _vm_btcm_init)
        return _vm_btcm_init(callback, evt_mask, user_data);

    return (VMINT)-1;
}
