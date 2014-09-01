#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_srv_get_visibility_t)(void);
_vm_btcm_srv_get_visibility_t _vm_btcm_srv_get_visibility = NULL;
VMINT vm_btcm_srv_get_visibility(void)
{
    if (NULL == _vm_btcm_srv_get_visibility)
        _vm_btcm_srv_get_visibility = (_vm_btcm_srv_get_visibility_t)vm_get_sym_entry("vm_btcm_srv_get_visibility");

    if (NULL != _vm_btcm_srv_get_visibility)
        return _vm_btcm_srv_get_visibility();

    return (VMINT)-1;
}
