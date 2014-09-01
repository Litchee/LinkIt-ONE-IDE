#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_get_mps_info_t)(const VMCHAR * msgBody, vm_srv_pns_msg_mps_struct * mpsPtr);
_vm_pn_get_mps_info_t _vm_pn_get_mps_info = NULL;

VMINT vm_pn_get_mps_info(const VMCHAR * msgBody, vm_srv_pns_msg_mps_struct * mpsPtr)
{
    if (NULL == _vm_pn_get_mps_info)
        _vm_pn_get_mps_info = (_vm_pn_get_mps_info_t)vm_get_sym_entry("vm_pn_get_mps_info");

    if (NULL != _vm_pn_get_mps_info)
        return _vm_pn_get_mps_info(msgBody,mpsPtr);

    return (VMINT)-1;
}