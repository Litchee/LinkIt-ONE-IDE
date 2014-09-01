#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT(*_vm_update_download_t)(VMINT handle, VMINT bOnCard, vm_update_app_callback callback, void* user_data);		
_vm_update_download_t _vm_update_download = NULL;	

VMINT vm_update_download(VMINT handle, VMINT bOnCard, vm_update_app_callback callback, void* user_data)
{
	if (_vm_update_download == NULL) {										
		_vm_update_download = (_vm_update_download_t)vm_get_sym_entry("vm_update_download");	
	}																
	if (_vm_update_download != NULL) {										
		return _vm_update_download(handle, bOnCard, callback, user_data);									
	}			
	return -1;	
}
