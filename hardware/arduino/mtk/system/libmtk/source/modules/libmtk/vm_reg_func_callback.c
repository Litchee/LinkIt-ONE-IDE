#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void(*_vm_reg_func_callback_t)(VMINT (*f)(VMSTR symbol));		
_vm_reg_func_callback_t _vm_reg_func_callback = NULL;	

void vm_reg_func_callback(VMINT (*f)(VMSTR symbol))
{
	if (_vm_reg_func_callback == NULL) {										
		_vm_reg_func_callback = (_vm_reg_func_callback_t)vm_get_sym_entry("vm_reg_func_callback");	
	}																
	if (_vm_reg_func_callback != NULL) {										
		_vm_reg_func_callback(f);									
	}			
}
