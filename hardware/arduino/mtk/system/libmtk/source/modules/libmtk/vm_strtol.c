#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef long(*_strtol_t)(const char * nptr, char **endptr, int base);		
	_strtol_t _strtol = NULL;	
long vm_strtol(const char * nptr, char **endptr, int base)
{
	if (_strtol == NULL) {										
		_strtol = (_strtol_t)vm_get_sym_entry("strtol");	
	}																
	if (_strtol != NULL) {										
	  return _strtol(nptr, endptr, base);									
	}			
	return 0;	
}
