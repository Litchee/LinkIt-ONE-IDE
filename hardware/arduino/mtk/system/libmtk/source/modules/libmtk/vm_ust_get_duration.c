#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT32 (*_vm_ust_get_duration_t)(VMUINT32 start,VMUINT32 end);
_vm_ust_get_duration_t _vm_ust_get_duration = NULL;
VMUINT32 vm_ust_get_duration(VMUINT32 start,VMUINT32 end)
{
	if (_vm_ust_get_duration == NULL)
		_vm_ust_get_duration = (_vm_ust_get_duration_t)vm_get_sym_entry("vm_ust_get_duration");
		
	if (_vm_ust_get_duration != NULL)
		return _vm_ust_get_duration(start,end);

        return -1;
		
}


