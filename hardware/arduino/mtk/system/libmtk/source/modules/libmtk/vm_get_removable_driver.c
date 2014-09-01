#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_removeable_driver_t)(void);
_vm_get_removeable_driver_t _vm_get_removeable_driver = NULL;


VMINT vm_get_removeable_driver(void) {
	if (_vm_get_removeable_driver == NULL)
		_vm_get_removeable_driver = (_vm_get_removeable_driver_t)vm_get_sym_entry("vm_get_removeable_driver");
		
	if (_vm_get_removeable_driver != NULL)
		return _vm_get_removeable_driver();
		
	return -1;
}
