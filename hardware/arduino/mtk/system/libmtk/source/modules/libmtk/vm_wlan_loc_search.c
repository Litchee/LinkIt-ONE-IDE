#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_loc_search_t)(void (*callback)(vm_wlan_loc_data_t * data, void * user_data), void * user_data);
_vm_wlan_loc_search_t _vm_wlan_loc_search = NULL;
VMINT vm_wlan_loc_search(void (*callback)(vm_wlan_loc_data_t * data, void * user_data), void * user_data)
{
	if (_vm_wlan_loc_search == NULL)
		_vm_wlan_loc_search = (_vm_wlan_loc_search_t)vm_get_sym_entry("vm_wlan_loc_search");
	
	if (_vm_wlan_loc_search != NULL)
		return _vm_wlan_loc_search(callback, user_data);
	else
		return -1;
}

