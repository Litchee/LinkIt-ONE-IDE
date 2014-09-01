#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_rtc_t)(VMUINT * rtc);
_vm_get_rtc_t _vm_get_rtc = NULL;
VMINT vm_get_rtc(VMUINT * rtc)
{
	if (_vm_get_rtc == NULL)
		_vm_get_rtc = (_vm_get_rtc_t)vm_get_sym_entry("vm_get_rtc");
		
	if (_vm_get_rtc != NULL)
		return _vm_get_rtc(rtc);

        return -1;
		
}


