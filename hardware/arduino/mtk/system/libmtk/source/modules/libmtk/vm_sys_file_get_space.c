#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_sys_file_get_space_t)(void);
	_vm_sys_file_get_space_t _vm_sys_file_get_space = NULL;	
VMINT vm_sys_file_get_space(void)
{
	if (_vm_sys_file_get_space == NULL)
		_vm_sys_file_get_space = (_vm_sys_file_get_space_t)vm_get_sym_entry("vm_sys_file_get_space");

	if (_vm_sys_file_get_space != NULL)
		return _vm_sys_file_get_space();
	else
		return -1;
}
