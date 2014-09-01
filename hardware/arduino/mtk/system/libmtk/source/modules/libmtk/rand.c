#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int(*_rand_t)(void);		
	_rand_t _rand = NULL;	
int rand(void)
{
	if (_rand == NULL) {										
		_rand = (_rand_t)vm_get_sym_entry("rand");	
	}																
	if (_rand != NULL) {										
		return _rand();									
	}			
	return 0;	
}
