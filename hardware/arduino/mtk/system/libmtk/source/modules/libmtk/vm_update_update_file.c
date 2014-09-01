#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT(*_vm_update_update_file_t)(void);		
_vm_update_update_file_t _vm_update_update_file = NULL;	

VMINT vm_update_update_file(void)
{
	if (_vm_update_update_file == NULL) {										
		_vm_update_update_file = (_vm_update_update_file_t)vm_get_sym_entry("vm_update_update_file");	
	}																
	if (_vm_update_update_file != NULL) {										
		return _vm_update_update_file();									
	}			
	return -1;	
}
