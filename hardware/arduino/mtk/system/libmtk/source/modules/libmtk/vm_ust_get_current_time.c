#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT32 (*_vm_ust_get_current_time_t)(void);
_vm_ust_get_current_time_t _vm_ust_get_current_time = NULL;
VMUINT32 vm_ust_get_current_time(void)
{
	if (_vm_ust_get_current_time == NULL)
		_vm_ust_get_current_time = (_vm_ust_get_current_time_t)vm_get_sym_entry("vm_ust_get_current_time");
		
	if (_vm_ust_get_current_time != NULL)
		return _vm_ust_get_current_time();

        return -1;
		
}


