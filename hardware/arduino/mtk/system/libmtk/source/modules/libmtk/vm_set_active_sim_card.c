#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_set_active_sim_card_t)(VMINT card_id);
_vm_set_active_sim_card_t _vm_set_active_sim_card = NULL;

VMINT vm_set_active_sim_card(VMINT card_id)
{
    if (NULL == _vm_set_active_sim_card)
        _vm_set_active_sim_card = (_vm_set_active_sim_card_t)vm_get_sym_entry("vm_set_active_sim_card");

    if (NULL != _vm_set_active_sim_card)
        return _vm_set_active_sim_card(card_id);

    return (VMINT )-1;
}
