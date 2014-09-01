#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT(*_vm_update_check_version_t)(VMSTR URL, VMINT port, VMINT apn, vm_update_app_callback callback, void* user_data);		
_vm_update_check_version_t _vm_update_check_version = NULL;	

VMINT vm_update_check_version(VMSTR URL, VMINT port, VMINT apn, vm_update_app_callback callback, void* user_data)
{
	if (_vm_update_check_version == NULL) {										
		_vm_update_check_version = (_vm_update_check_version_t)vm_get_sym_entry("vm_update_check_version");	
	}																
	if (_vm_update_check_version != NULL) {										
		return _vm_update_check_version(URL, port, apn, callback, user_data);									
	}			
	return -1;	
}
