#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_vsprintf_t)(char *buf, const char *fmt, va_list args);
_vm_vsprintf_t _vm_vsprintf = NULL;

int vm_vsprintf(char *buf, const char *fmt, va_list args)
{
    int  ret = {-1};
    if (NULL == _vm_vsprintf)
        _vm_vsprintf = (_vm_vsprintf_t)vm_get_sym_entry("vm_vsprintf");

    if (NULL != _vm_vsprintf)
        return _vm_vsprintf(buf,fmt,args);

    return ret;
}
