#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT(*_vm_update_cancel_t)(VMINT handle);		
_vm_update_cancel_t _vm_update_cancel = NULL;	

VMINT vm_update_cancel(VMINT handle)
{
	if (_vm_update_cancel == NULL) {										
		_vm_update_cancel = (_vm_update_cancel_t)vm_get_sym_entry("vm_update_cancel");	
	}																
	if (_vm_update_cancel != NULL) {										
		return _vm_update_cancel(handle);									
	}			
	return -1;	
}
