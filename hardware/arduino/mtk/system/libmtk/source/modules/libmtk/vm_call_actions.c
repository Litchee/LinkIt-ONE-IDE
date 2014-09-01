#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_call_actions_t)(const vm_call_actions_data* data);
_vm_call_actions_t _vm_call_actions = NULL;

VMINT vm_call_actions(const vm_call_actions_data* data)
{
    if (NULL == _vm_call_actions)
        _vm_call_actions = (_vm_call_actions_t)vm_get_sym_entry("vm_call_actions");

    if (NULL != _vm_call_actions)
        return _vm_call_actions(data);
		
		return -1;
    
}
