#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sim_max_card_count_t)(void);
_vm_sim_max_card_count_t _vm_sim_max_card_count = NULL;

VMINT vm_sim_max_card_count(void)
{
    if (NULL == _vm_sim_max_card_count)
        _vm_sim_max_card_count = (_vm_sim_max_card_count_t)vm_get_sym_entry("vm_sim_max_card_count");

    if (NULL != _vm_sim_max_card_count)
        return _vm_sim_max_card_count();

    return (VMINT )-1;
}
