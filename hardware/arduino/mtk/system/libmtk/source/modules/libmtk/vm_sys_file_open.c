#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMFILE (*_vm_sys_file_open_t)(VMUINT mode, VMUINT binary);
	_vm_sys_file_open_t _vm_sys_file_open = NULL;	
VMFILE vm_sys_file_open(VMUINT mode, VMUINT binary)
{
	if (_vm_sys_file_open == NULL)
		_vm_sys_file_open = (_vm_sys_file_open_t)vm_get_sym_entry("vm_sys_file_open");

	if (_vm_sys_file_open != NULL)
		return _vm_sys_file_open(mode, binary);
	else
		return -1;
}
