#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_strtoi_t)(char* s);
_strtoi_t _strtoi = NULL;

int strtoi(char* s)
{
    int  ret = {-1};
    if (NULL == _strtoi)
        _strtoi = (_strtoi_t)vm_get_sym_entry("strtoi");

    if (NULL != _strtoi)
        return _strtoi(s);

    return ret;
}
