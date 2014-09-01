#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef operator_t (*_vm_sim_get_operator_t)(void);
_vm_sim_get_operator_t _vm_sim_get_operator = NULL;

operator_t vm_sim_get_operator(void)
{
    if (NULL == _vm_sim_get_operator)
        _vm_sim_get_operator = (_vm_sim_get_operator_t)vm_get_sym_entry("vm_sim_get_operator");
    if (NULL != _vm_sim_get_operator)
        return _vm_sim_get_operator();
    return (operator_t)-1;
}