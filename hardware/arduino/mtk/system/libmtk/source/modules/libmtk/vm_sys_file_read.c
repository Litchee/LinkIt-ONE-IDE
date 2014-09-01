#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sys_file_read_t)(VMFILE handle, void * data, VMUINT length, VMUINT *nread);
	_vm_sys_file_read_t _vm_sys_file_read = NULL;	
VMINT vm_sys_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread)
{
	if (_vm_sys_file_read == NULL)
		_vm_sys_file_read = (_vm_sys_file_read_t)vm_get_sym_entry("vm_sys_file_read");

	if (_vm_sys_file_read != NULL)
		return _vm_sys_file_read(handle, data, length, nread);
	else
		return -1;
}
