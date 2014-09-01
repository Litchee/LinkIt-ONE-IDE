#include "vmsys.h"
#include "vmdns.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_dns_start_t)(VMUINT32 port, VMCHAR *config_path, VMCHAR *domain_path);
_vm_dns_start_t _vm_dns_start = NULL;
VMINT vm_dns_start(VMUINT32 port, VMCHAR *config_path, VMCHAR *domain_path)
{
    if (NULL == _vm_dns_start)
        _vm_dns_start = (_vm_dns_start_t)vm_get_sym_entry("vm_dns_start");

    if (NULL != _vm_dns_start)
        return _vm_dns_start(port, config_path, domain_path);

    return -1;

}


