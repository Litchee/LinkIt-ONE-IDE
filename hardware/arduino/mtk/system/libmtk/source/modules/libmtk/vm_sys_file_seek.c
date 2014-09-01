#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sys_file_seek_t)(VMFILE handle, VMINT offset, VMINT base);
	_vm_sys_file_seek_t _vm_sys_file_seek = NULL;	
VMINT vm_sys_file_seek(VMFILE handle, VMINT offset, VMINT base)
{
	if (_vm_sys_file_seek == NULL)
		_vm_sys_file_seek = (_vm_sys_file_seek_t)vm_get_sym_entry("vm_sys_file_seek");

	if (_vm_sys_file_seek != NULL)
		return _vm_sys_file_seek(handle, offset, base);
	else
		return -1;
}
