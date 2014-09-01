#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_nw_info_get_service_availability_t)(VMINT sim_card);
_vm_srv_nw_info_get_service_availability_t _vm_srv_nw_info_get_service_availability = NULL;

VMINT vm_srv_nw_info_get_service_availability(VMINT sim_card)
{
    if (NULL == _vm_srv_nw_info_get_service_availability)
        _vm_srv_nw_info_get_service_availability = (_vm_srv_nw_info_get_service_availability_t)vm_get_sym_entry("vm_srv_nw_info_get_service_availability");

    if (NULL != _vm_srv_nw_info_get_service_availability)
        return _vm_srv_nw_info_get_service_availability(sim_card);

    return (VMINT )-1;
}
