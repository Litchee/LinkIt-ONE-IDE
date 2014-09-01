#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_sim_state_t (*_vm_sim_get_card_status_t)(VMINT sim);
_vm_sim_get_card_status_t _vm_sim_get_card_status = NULL;

vm_sim_state_t vm_sim_get_card_status(VMINT sim)
{
    if (NULL == _vm_sim_get_card_status)
        _vm_sim_get_card_status = (_vm_sim_get_card_status_t)vm_get_sym_entry("vm_sim_get_card_status");
    if (NULL != _vm_sim_get_card_status)
        return _vm_sim_get_card_status(sim);
    return (vm_sim_state_t)-1;
}