#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sim_get_active_sim_card_t)(void);
_vm_sim_get_active_sim_card_t _vm_sim_get_active_sim_card = NULL;

VMINT vm_sim_get_active_sim_card(void)
{
    if (NULL == _vm_sim_get_active_sim_card)
        _vm_sim_get_active_sim_card = (_vm_sim_get_active_sim_card_t)vm_get_sym_entry("vm_sim_get_active_sim_card");

    if (NULL != _vm_sim_get_active_sim_card)
        return _vm_sim_get_active_sim_card();

    return (VMINT )-1;
}
