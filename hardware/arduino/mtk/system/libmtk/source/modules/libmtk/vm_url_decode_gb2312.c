#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_url_decode_gb2312_t)(VMSTR dst, VMUINT size, VMSTR src);
_vm_url_decode_gb2312_t _vm_url_decode_gb2312 = NULL;

VMUINT vm_url_decode_gb2312(VMSTR dst, VMUINT size, VMSTR src) {
	if (_vm_url_decode_gb2312 == NULL)
		_vm_url_decode_gb2312 = (_vm_url_decode_gb2312_t)vm_get_sym_entry("vm_url_decode_gb2312");
		
	if (_vm_url_decode_gb2312 != NULL)
		return _vm_url_decode_gb2312(dst, size, src);
	
	return 0;
}
