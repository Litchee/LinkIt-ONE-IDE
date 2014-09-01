#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_set_cust_apn_info_t)(const vm_dtcnt_info_t * info, VMUINT32 * dtacct);
_vm_set_cust_apn_info_t _vm_set_cust_apn_info = NULL;

VMINT vm_set_cust_apn_info(const vm_dtcnt_info_t * info, VMUINT32 * dtacct)
{
    if (NULL == _vm_set_cust_apn_info)
        _vm_set_cust_apn_info = (_vm_set_cust_apn_info_t)vm_get_sym_entry("vm_set_cust_apn_info");

    if (NULL != _vm_set_cust_apn_info)
        return _vm_set_cust_apn_info(info, dtacct);

    return (VMINT )-1;
}
