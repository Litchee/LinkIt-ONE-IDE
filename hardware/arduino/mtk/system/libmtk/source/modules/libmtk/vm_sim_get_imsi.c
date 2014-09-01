#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMSTR (*_vm_sim_get_imsi_t)(void);
_vm_sim_get_imsi_t _vm_sim_get_imsi = NULL;

VMSTR vm_sim_get_imsi(void)
{
    if (NULL == _vm_sim_get_imsi)
        _vm_sim_get_imsi = (_vm_sim_get_imsi_t)vm_get_sym_entry("vm_sim_get_imsi");
    if (NULL != _vm_sim_get_imsi)
        return _vm_sim_get_imsi();
    return (VMSTR)-1;
}