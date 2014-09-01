#include "vmsys.h"
#include "vmwdt.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_wdt_feed_t)(VMINT handle);
_vm_wdt_feed_t _vm_wdt_feed = NULL;

void vm_wdt_feed(VMINT handle)
{
    if (NULL == _vm_wdt_feed)
        _vm_wdt_feed = (_vm_wdt_feed_t)vm_get_sym_entry("vm_wdt_feed");

    if (NULL != _vm_wdt_feed)
        _vm_wdt_feed(handle);
}
