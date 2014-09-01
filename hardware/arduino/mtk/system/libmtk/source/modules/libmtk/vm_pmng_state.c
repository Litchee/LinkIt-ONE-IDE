#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_PROCESS_STATUS (*_vm_pmng_state_t)(VM_P_HANDLE p_handle);
_vm_pmng_state_t _vm_pmng_state = NULL;
VM_PROCESS_STATUS vm_pmng_state(VM_P_HANDLE p_handle)
{
	if (_vm_pmng_state == NULL)
		_vm_pmng_state = (_vm_pmng_state_t)vm_get_sym_entry("vm_pmng_state");
	if (_vm_pmng_state != NULL)
		return _vm_pmng_state(p_handle);
	return VM_PMNG_UNLOAD;
}
