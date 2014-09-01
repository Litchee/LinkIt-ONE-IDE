#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMSTR (*_vm_sim_get_imei_t)(void);
_vm_sim_get_imei_t _vm_sim_get_imei = NULL;

VMSTR vm_sim_get_imei(void)
{
    if (NULL == _vm_sim_get_imei)
        _vm_sim_get_imei = (_vm_sim_get_imei_t)vm_get_sym_entry("vm_sim_get_imei");
    if (NULL != _vm_sim_get_imei)
        return _vm_sim_get_imei();
    return (VMSTR)-1;
}