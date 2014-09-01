#include "vmsys.h"
#include "vmpwr.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_fly_mode_is_network_service_available_t)(void);
_vm_fly_mode_is_network_service_available_t _vm_fly_mode_is_network_service_available = NULL;

VMBOOL vm_fly_mode_is_network_service_available(void)
{
    if (NULL == _vm_fly_mode_is_network_service_available)
        _vm_fly_mode_is_network_service_available = (_vm_fly_mode_is_network_service_available_t)vm_get_sym_entry("vm_fly_mode_is_network_service_available");

    if (NULL != _vm_fly_mode_is_network_service_available)
        return _vm_fly_mode_is_network_service_available();

    return (VMBOOL)-1;
}