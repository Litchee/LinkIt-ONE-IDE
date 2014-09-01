#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef double(*_atof_t)(const char * nptr);		
	_atof_t _atof = NULL;	
double vm_atof(const char * nptr)
{
	if (_atof == NULL) {										
		_atof = (_atof_t)vm_get_sym_entry("atof");	
	}																
	if (_atof != NULL) {										
	  return _atof(nptr);									
	}			
	return 0;	
}
