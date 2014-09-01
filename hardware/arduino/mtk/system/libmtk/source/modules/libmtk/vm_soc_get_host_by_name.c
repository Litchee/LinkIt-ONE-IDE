#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_get_host_by_name_t)(VMINT apn, const VMCHAR * host, vm_soc_dns_result * result, VMINT (*callback)(vm_soc_dns_result *));
_vm_soc_get_host_by_name_t _vm_soc_get_host_by_name = NULL;

VMINT vm_soc_get_host_by_name(VMINT apn, const VMCHAR * host, vm_soc_dns_result * result, VMINT (*callback)(vm_soc_dns_result *))
{
    if (NULL == _vm_soc_get_host_by_name)
        _vm_soc_get_host_by_name = (_vm_soc_get_host_by_name_t)vm_get_sym_entry("vm_soc_get_host_by_name");

    if (NULL != _vm_soc_get_host_by_name)
        return _vm_soc_get_host_by_name(apn,host,result,callback);

    return (VMINT )-1;
}
