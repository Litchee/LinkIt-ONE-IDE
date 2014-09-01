#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_delete_process_t)(VM_P_HANDLE p_handle);
_vm_pmng_delete_process_t _vm_pmng_delete_process = NULL;
VMINT vm_pmng_delete_process(VM_P_HANDLE p_handle)
{
	if (_vm_pmng_delete_process == NULL)
		_vm_pmng_delete_process = (_vm_pmng_delete_process_t)vm_get_sym_entry("vm_pmng_delete_process");
	if (_vm_pmng_delete_process != NULL)
		return _vm_pmng_delete_process(p_handle);
	return -1;
}