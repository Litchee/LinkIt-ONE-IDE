#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_get_mps_info_ex_t)(const VMCHAR * msgBody, vm_srv_pns_msg_mps_struct_ex* mpsPtr);
_vm_pn_get_mps_info_ex_t _vm_pn_get_mps_info_ex = NULL;

VMINT vm_pn_get_mps_info_ex(const VMCHAR * msgBody, vm_srv_pns_msg_mps_struct_ex * mpsPtr)
{
    if (NULL == _vm_pn_get_mps_info_ex)
        _vm_pn_get_mps_info_ex = (_vm_pn_get_mps_info_ex_t)vm_get_sym_entry("vm_pn_get_mps_info_ex");

    if (NULL != _vm_pn_get_mps_info_ex)
        return _vm_pn_get_mps_info_ex(msgBody,mpsPtr);

    return (VMINT)-1;
}