#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_has_sim_card_t)(void);
_vm_has_sim_card_t _vm_has_sim_card = NULL;

VMINT vm_has_sim_card(void)
{
    if (NULL == _vm_has_sim_card)
        _vm_has_sim_card = (_vm_has_sim_card_t)vm_get_sym_entry("vm_has_sim_card");

    if (NULL != _vm_has_sim_card)
        return _vm_has_sim_card();

    return (VMINT )-1;
}
