#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_get_today_from_2000_t)(void);
_get_today_from_2000_t _get_today_from_2000 = NULL;

VMINT get_today_from_2000(void)
{
    if (NULL == _get_today_from_2000)
        _get_today_from_2000 = (_get_today_from_2000_t)vm_get_sym_entry("get_today_from_2000");

    if (NULL != _get_today_from_2000)
        return _get_today_from_2000();

    return (VMINT )-1;
}
