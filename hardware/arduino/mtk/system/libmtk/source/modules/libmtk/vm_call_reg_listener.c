#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_call_reg_listener_t)(vm_call_listener_func func);
_vm_call_reg_listener_t _vm_call_reg_listener = NULL;

VMINT vm_call_reg_listener(vm_call_listener_func func)
{
    if (NULL == _vm_call_reg_listener)
        _vm_call_reg_listener = (_vm_call_reg_listener_t)vm_get_sym_entry("vm_call_reg_listener");

    if (NULL != _vm_call_reg_listener)
        return _vm_call_reg_listener(func);
		
		return -1;
    
}
