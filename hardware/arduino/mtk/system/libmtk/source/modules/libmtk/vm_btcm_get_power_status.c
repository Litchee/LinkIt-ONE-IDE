#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_get_power_status_t)(void);
_vm_btcm_get_power_status_t _vm_btcm_get_power_status = NULL;
VMINT vm_btcm_get_power_status(void)
{
    if (NULL == _vm_btcm_get_power_status)
        _vm_btcm_get_power_status = (_vm_btcm_get_power_status_t)vm_get_sym_entry("vm_btcm_get_power_status");

    if (NULL != _vm_btcm_get_power_status)
        return _vm_btcm_get_power_status();

    return (VMINT)-1;
}
