#include "vmsys.h"
#include "vmwdt.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_wdt_stop_t)(VMINT handle);
_vm_wdt_stop_t _vm_wdt_stop = NULL;

void vm_wdt_stop(VMINT handle)
{
    if (NULL == _vm_wdt_stop)
        _vm_wdt_stop = (_vm_wdt_stop_t)vm_get_sym_entry("vm_wdt_stop");

    if (NULL != _vm_wdt_stop)
        _vm_wdt_stop(handle);
}
