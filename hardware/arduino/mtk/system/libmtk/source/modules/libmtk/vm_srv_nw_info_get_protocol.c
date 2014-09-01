#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_nw_info_get_protocol_t)(VMINT sim_card);
_vm_srv_nw_info_get_protocol_t _vm_srv_nw_info_get_protocol = NULL;

VMINT vm_srv_nw_info_get_protocol(VMINT sim_card)
{
    if (NULL == _vm_srv_nw_info_get_protocol)
        _vm_srv_nw_info_get_protocol = (_vm_srv_nw_info_get_protocol_t)vm_get_sym_entry("vm_srv_nw_info_get_protocol");

    if (NULL != _vm_srv_nw_info_get_protocol)
        return _vm_srv_nw_info_get_protocol(sim_card);

    return (VMINT )-1;
}
