#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sys_file_delete_t)(void);
	_vm_sys_file_delete_t _vm_sys_file_delete = NULL;	
VMINT vm_sys_file_delete(void)
{
	if (_vm_sys_file_delete == NULL)
		_vm_sys_file_delete = (_vm_sys_file_delete_t)vm_get_sym_entry("vm_sys_file_delete");

	if (_vm_sys_file_delete != NULL)
		return _vm_sys_file_delete();
	else
		return -1;
}
