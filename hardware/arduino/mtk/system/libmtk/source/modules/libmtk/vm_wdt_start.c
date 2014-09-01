#include "vmsys.h"
#include "vmwdt.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wdt_start_t)(VMUINT tick);
_vm_wdt_start_t _vm_wdt_start = NULL;

VMINT vm_wdt_start(VMUINT tick)
{
    if (NULL == _vm_wdt_start)
        _vm_wdt_start = (_vm_wdt_start_t)vm_get_sym_entry("vm_wdt_start");

    if (NULL != _vm_wdt_start)
        return _vm_wdt_start(tick);
        
    return -1;
}
