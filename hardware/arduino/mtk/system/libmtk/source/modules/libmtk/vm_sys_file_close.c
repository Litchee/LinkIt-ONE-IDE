#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_sys_file_close_t)(VMFILE h);
	_vm_sys_file_close_t _vm_sys_file_close = NULL;	
void vm_sys_file_close(VMFILE h)
{
	if (_vm_sys_file_close == NULL)
		_vm_sys_file_close = (_vm_sys_file_close_t)vm_get_sym_entry("vm_sys_file_close");

	if (_vm_sys_file_close != NULL)
		_vm_sys_file_close(h);
}
