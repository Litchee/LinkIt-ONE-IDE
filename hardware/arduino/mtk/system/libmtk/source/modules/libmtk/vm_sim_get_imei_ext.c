#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMSTR (*_vm_sim_get_imei_ext_t)(VMINT sim);
_vm_sim_get_imei_ext_t _vm_sim_get_imei_ext = NULL;

VMSTR vm_sim_get_imei_ext(VMINT sim)
{
    if (NULL == _vm_sim_get_imei_ext)
        _vm_sim_get_imei_ext = (_vm_sim_get_imei_ext_t)vm_get_sym_entry("vm_sim_get_imei_ext");
    if (NULL != _vm_sim_get_imei_ext)
        return _vm_sim_get_imei_ext(sim);
    return (VMSTR)-1;
}