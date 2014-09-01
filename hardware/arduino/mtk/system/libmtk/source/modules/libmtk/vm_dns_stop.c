#include "vmsys.h"
#include "vmdns.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dns_stop_t)(void);
_vm_dns_stop_t _vm_dns_stop = NULL;
VMINT vm_dns_stop(void)
{
    if (NULL == _vm_dns_stop)
        _vm_dns_stop = (_vm_dns_stop_t)vm_get_sym_entry("vm_dns_stop");

    if (NULL != _vm_dns_stop)
        return _vm_dns_stop();

    return -1;

}


