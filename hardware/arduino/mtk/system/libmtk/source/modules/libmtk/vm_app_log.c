#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_app_log_t)(char* info);
_vm_app_log_t _vm_app_log = NULL;
void vm_app_log(char* info)
{
	if (_vm_app_log == NULL)
		_vm_app_log = (_vm_app_log_t)vm_get_sym_entry("vm_app_log");
	
	if (_vm_app_log != NULL)
		_vm_app_log(info);
}
