#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT(*_vm_update_check_launch_t)(VMWSTR path, VMWSTR new_path);		
_vm_update_check_launch_t _vm_update_check_launch = NULL;	

VMINT vm_update_check_launch(VMWSTR path, VMWSTR new_path)
{
	if (_vm_update_check_launch == NULL) {										
		_vm_update_check_launch = (_vm_update_check_launch_t)vm_get_sym_entry("vm_update_check_launch");	
	}																
	if (_vm_update_check_launch != NULL) {										
		return _vm_update_check_launch(path, new_path);									
	}			
	return -1;	
}
