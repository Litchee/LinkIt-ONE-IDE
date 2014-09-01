#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_loc_search_abort_t)(VMINT handle);
_vm_wlan_loc_search_abort_t _vm_wlan_loc_search_abort = NULL;
VMINT vm_wlan_loc_search_abort(VMINT handle)
{
	if (_vm_wlan_loc_search_abort == NULL)
		_vm_wlan_loc_search_abort = (_vm_wlan_loc_search_abort_t)vm_get_sym_entry("vm_wlan_loc_search_abort");
	
	if (_vm_wlan_loc_search_abort != NULL)
		return _vm_wlan_loc_search_abort(handle);
	else
		return -1;
}

