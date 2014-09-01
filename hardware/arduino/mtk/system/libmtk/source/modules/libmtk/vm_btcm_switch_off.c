#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_switch_off_t)(void);
_vm_btcm_switch_off_t _vm_btcm_switch_off = NULL;
VMINT vm_btcm_switch_off(void)
{
    if (NULL == _vm_btcm_switch_off)
        _vm_btcm_switch_off = (_vm_btcm_switch_off_t)vm_get_sym_entry("vm_btcm_switch_off");

    if (NULL != _vm_btcm_switch_off)
        return _vm_btcm_switch_off();

    return (VMINT)-1;
}
