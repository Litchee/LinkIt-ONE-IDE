#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_sscanf_t)(const char * str, const char *format, va_list args);
_vm_sscanf_t _vm_sscanf = NULL;
int vm_sscanf(const char *str, const char *format, ...)
{
	VMINT result = -1;
	if (_vm_sscanf == NULL) {										
		_vm_sscanf = (_vm_sscanf_t)vm_get_sym_entry("vm_sscanf");	
	}			
														
	if (_vm_sscanf != NULL) 
	{
		va_list args;   
  	va_start(args, format );
  	result = _vm_sscanf(str, format, args);
  	va_end( args );						
	}			
	return result;
}
