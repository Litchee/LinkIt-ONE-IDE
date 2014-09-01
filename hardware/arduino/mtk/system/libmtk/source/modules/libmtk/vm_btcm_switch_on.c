#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_switch_on_t)(void);
_vm_btcm_switch_on_t _vm_btcm_switch_on = NULL;
VMINT vm_btcm_switch_on(void)
{
    if (NULL == _vm_btcm_switch_on)
        _vm_btcm_switch_on = (_vm_btcm_switch_on_t)vm_get_sym_entry("vm_btcm_switch_on");

    if (NULL != _vm_btcm_switch_on)
        return _vm_btcm_switch_on();

    return (VMINT)-1;
}
