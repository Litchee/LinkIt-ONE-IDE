#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_sprintf_t)( char * buf, const char * fmt, ... );
_vm_sprintf_t _vm_sprintf = NULL;

int vm_sprintf( char * buf, const char * fmt, ... )
{
    int  ret = {-1};
    if (NULL == _vm_sprintf)
        _vm_sprintf = (_vm_sprintf_t)vm_get_sym_entry("vm_vsprintf");

    if (NULL != _vm_sprintf)
		{
			va_list args;   
	  	va_start( args, fmt );
	  	ret = _vm_sprintf(buf, fmt, args);
	  	va_end( args );						
		}			
    return ret;
}
