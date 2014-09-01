#include "vmsys.h"
#include "vmdns.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dns_get_state_t)(void);
_vm_dns_get_state_t _vm_dns_get_state = NULL;
VMINT vm_dns_get_state(void)
{
    if (NULL == _vm_dns_get_state)
        _vm_dns_get_state = (_vm_dns_get_state_t)vm_get_sym_entry("vm_dns_get_state");

    if (NULL != _vm_dns_get_state)
        return _vm_dns_get_state();

    return -1;

}


