#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_full_path_by_short_name_t)(VMWSTR short_name, VMWSTR full_path);
_vm_get_full_path_by_short_name_t _vm_get_full_path_by_short_name = NULL;
VMINT vm_get_full_path_by_short_name(VMWSTR short_name, VMWSTR full_path)
{
	if (_vm_get_full_path_by_short_name == NULL)
		_vm_get_full_path_by_short_name = (_vm_get_full_path_by_short_name_t)vm_get_sym_entry("vm_get_full_path_by_short_name");
	if (_vm_get_full_path_by_short_name != NULL)
		return _vm_get_full_path_by_short_name(short_name, full_path);
	return -1;
}
