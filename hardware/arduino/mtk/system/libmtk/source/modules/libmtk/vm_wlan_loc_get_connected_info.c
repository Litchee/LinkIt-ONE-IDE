#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_loc_get_connected_info_t)(vm_wlan_loc_supc_abm_bss_info_struct * info);
_vm_wlan_loc_get_connected_info_t _vm_wlan_loc_get_connected_info = NULL;
VMINT vm_wlan_loc_get_connected_info(vm_wlan_loc_supc_abm_bss_info_struct * info)
{
	if (_vm_wlan_loc_get_connected_info == NULL)
		_vm_wlan_loc_get_connected_info = (_vm_wlan_loc_get_connected_info_t)vm_get_sym_entry("vm_wlan_loc_get_connected_info");
	
	if (_vm_wlan_loc_get_connected_info != NULL)
		return _vm_wlan_loc_get_connected_info(info);
	else
		return -1;
}
