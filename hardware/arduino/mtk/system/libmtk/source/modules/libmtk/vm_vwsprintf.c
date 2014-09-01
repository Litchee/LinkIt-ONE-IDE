#include "vmsys.h"
#include "vmstdlib.h"

typedef int (*_vm_vwsprintf_t)(VMWSTR buf, VMINT size, const VMWSTR fmt, va_list args);
_vm_vwsprintf_t _vm_vwsprintf = NULL;

VMINT vm_vwsprintf(VMWSTR buf, VMINT size, const VMWSTR fmt, va_list args)
{
    int  ret = {-1};
    if (NULL == _vm_vwsprintf)
        _vm_vwsprintf = (_vm_vwsprintf_t)vm_get_sym_entry("vm_vwsprintf");

    if (NULL != _vm_vwsprintf)
    {
        ret = _vm_vwsprintf(buf, size, fmt, args);					
    }
    
    return ret;
}


