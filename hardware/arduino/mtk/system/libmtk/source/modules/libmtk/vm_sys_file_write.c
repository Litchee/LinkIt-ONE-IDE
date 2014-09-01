#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sys_file_write_t)(VMFILE handle, void * data, VMUINT length, VMUINT * written);
	_vm_sys_file_write_t _vm_sys_file_write = NULL;	
VMINT vm_sys_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written)
{
	if (_vm_sys_file_write == NULL)
		_vm_sys_file_write = (_vm_sys_file_write_t)vm_get_sym_entry("vm_sys_file_write");

	if (_vm_sys_file_write != NULL)
		return _vm_sys_file_write(handle, data, length, written);
	else
		return -1;
}
