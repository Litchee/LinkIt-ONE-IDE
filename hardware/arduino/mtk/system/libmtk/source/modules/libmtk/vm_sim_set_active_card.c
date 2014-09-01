#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_sim_set_active_card_t)(VMINT sim);
_vm_sim_set_active_card_t _vm_sim_set_active_card = NULL;

VMBOOL vm_sim_set_active_card(VMINT sim)
{
    if (NULL == _vm_sim_set_active_card)
        _vm_sim_set_active_card = (_vm_sim_set_active_card_t)vm_get_sym_entry("vm_sim_set_active_card");
    if (NULL != _vm_sim_set_active_card)
        return _vm_sim_set_active_card(sim);
    return (VMBOOL)-1;
}