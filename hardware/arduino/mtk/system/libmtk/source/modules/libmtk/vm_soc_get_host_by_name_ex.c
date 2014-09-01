#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_get_host_by_name_ex_t)(VMINT apn, const VMCHAR * host, vm_soc_dns_result * result, VMINT (*callback)(VMINT, vm_soc_dns_result *, void *), void *user_data);
_vm_soc_get_host_by_name_ex_t _vm_soc_get_host_by_name_ex = NULL;

VMINT vm_soc_get_host_by_name_ex(VMINT apn, const VMCHAR * host, vm_soc_dns_result * result, VMINT (*callback)(VMINT, vm_soc_dns_result *, void *), void *user_data)
{
    if (NULL == _vm_soc_get_host_by_name_ex)
        _vm_soc_get_host_by_name_ex = (_vm_soc_get_host_by_name_ex_t)vm_get_sym_entry("vm_soc_get_host_by_name_ex");
    if (NULL != _vm_soc_get_host_by_name_ex)
        return _vm_soc_get_host_by_name_ex(apn,host,result,callback,user_data);
    return (VMINT)-1;
}