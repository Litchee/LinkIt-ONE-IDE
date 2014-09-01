#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_sim_state_t (*_vm_get_sim_card_status_t)(VMINT card_id);
_vm_get_sim_card_status_t _vm_get_sim_card_status = NULL;

vm_sim_state_t vm_get_sim_card_status(VMINT card_id)
{
    vm_sim_state_t  ret = {-1};
    if (NULL == _vm_get_sim_card_status)
        _vm_get_sim_card_status = (_vm_get_sim_card_status_t)vm_get_sym_entry("vm_get_sim_card_status");

    if (NULL != _vm_get_sim_card_status)
        return _vm_get_sim_card_status(card_id);

    return ret;
}
