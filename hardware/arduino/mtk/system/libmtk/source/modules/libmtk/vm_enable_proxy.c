#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_enable_proxy_t)(VMINT use_proxy);
_vm_enable_proxy_t _vm_enable_proxy = NULL;

void vm_enable_proxy(VMINT use_proxy)
{
    if (NULL == _vm_enable_proxy)
        _vm_enable_proxy = (_vm_enable_proxy_t)vm_get_sym_entry("vm_enable_proxy");

    if (NULL != _vm_enable_proxy)
        _vm_enable_proxy(use_proxy);

    
}
