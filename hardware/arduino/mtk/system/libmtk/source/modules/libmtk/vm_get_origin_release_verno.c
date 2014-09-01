#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_origin_release_verno_t)(VMCHAR *value, VMUINT len);
_vm_get_origin_release_verno_t _vm_get_origin_release_verno = NULL;

VMUINT vm_get_origin_release_verno(VMCHAR *value, VMUINT len)
{
	if (_vm_get_origin_release_verno == NULL)
	{
		_vm_get_origin_release_verno = (_vm_get_origin_release_verno_t) vm_get_sym_entry("vm_get_origin_release_verno");
	}
	
	if (_vm_get_origin_release_verno != NULL)
	{
		return _vm_get_origin_release_verno(value, len);
	}
	
	return (VMUINT) 0;
}
