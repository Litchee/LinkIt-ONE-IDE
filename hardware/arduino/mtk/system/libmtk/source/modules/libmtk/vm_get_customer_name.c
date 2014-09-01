#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_customer_name_t)(VMCHAR *value, VMUINT len);
_vm_get_customer_name_t _vm_get_customer_name = NULL;

VMUINT vm_get_customer_name(VMCHAR *value, VMUINT len)
{
	if (_vm_get_customer_name == NULL)
	{
		_vm_get_customer_name = (_vm_get_customer_name_t) vm_get_sym_entry("vm_get_customer_name");
	}
	
	if (_vm_get_customer_name != NULL)
	{
		return _vm_get_customer_name(value, len);
	}
	
	return (VMUINT) 0;
}
