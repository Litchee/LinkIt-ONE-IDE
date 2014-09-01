#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_curr_utc_t)(VMUINT * utc);
_vm_get_curr_utc_t _vm_get_curr_utc = NULL;
VMINT vm_get_curr_utc(VMUINT * utc)
{
	if (_vm_get_curr_utc == NULL)
		_vm_get_curr_utc = (_vm_get_curr_utc_t)vm_get_sym_entry("vm_get_curr_utc");
		
	if (_vm_get_curr_utc != NULL)
		return _vm_get_curr_utc(utc);

        return -1;
		
}


