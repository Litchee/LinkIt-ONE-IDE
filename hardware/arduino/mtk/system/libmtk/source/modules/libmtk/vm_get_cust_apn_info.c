#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_cust_apn_info_t)(vm_dtcnt_info_t * info);
_vm_get_cust_apn_info_t _vm_get_cust_apn_info = NULL;

VMINT vm_get_cust_apn_info(vm_dtcnt_info_t * info)
{
    if (NULL == _vm_get_cust_apn_info)
        _vm_get_cust_apn_info = (_vm_get_cust_apn_info_t)vm_get_sym_entry("vm_get_cust_apn_info");

    if (NULL != _vm_get_cust_apn_info)
        return _vm_get_cust_apn_info(info);

    return (VMINT )-1;
}
