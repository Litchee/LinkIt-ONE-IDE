#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int(*_srand_t)(unsigned int seed);		
	_srand_t _srand = NULL;	
void srand(unsigned int seed)
{
	if (_srand == NULL) {										
		_srand = (_srand_t)vm_get_sym_entry("srand");	
	}																
	if (_srand != NULL) {										
	  _srand(seed);									
	}			

}
