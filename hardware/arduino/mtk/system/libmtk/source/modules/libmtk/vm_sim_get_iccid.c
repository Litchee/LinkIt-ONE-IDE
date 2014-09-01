#include "vmsys.h"
#include "vmsim.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sim_get_iccid_t)(VMINT sim, vm_sim_get_iccid_cb callback, VMCHAR* iccid, VMINT buff_len, void* user_data);
_vm_sim_get_iccid_t _vm_sim_get_iccid = NULL;

VMINT vm_sim_get_iccid(VMINT sim, vm_sim_get_iccid_cb callback, VMCHAR* iccid, VMINT buff_len, void* user_data)
{
    if (NULL == _vm_sim_get_iccid)
        _vm_sim_get_iccid = (_vm_sim_get_iccid_t)vm_get_sym_entry("vm_sim_get_iccid");

    if (NULL != _vm_sim_get_iccid)
        return _vm_sim_get_iccid(sim,callback,iccid,buff_len,user_data);

    return (VMINT )-1;
}
