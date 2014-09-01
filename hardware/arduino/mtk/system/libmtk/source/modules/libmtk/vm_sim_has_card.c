#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_sim_has_card_t)(void);
_vm_sim_has_card_t _vm_sim_has_card = NULL;

VMBOOL vm_sim_has_card(void)
{
    if (NULL == _vm_sim_has_card)
        _vm_sim_has_card = (_vm_sim_has_card_t)vm_get_sym_entry("vm_sim_has_card");
    if (NULL != _vm_sim_has_card)
        return _vm_sim_has_card();
    return (VMBOOL)-1;
}