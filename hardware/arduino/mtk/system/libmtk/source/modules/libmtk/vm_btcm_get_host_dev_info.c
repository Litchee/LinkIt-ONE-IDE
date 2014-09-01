#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_get_host_dev_info_t)(vm_srv_bt_cm_dev_struct * info);
_vm_btcm_get_host_dev_info_t _vm_btcm_get_host_dev_info = NULL;
VMINT vm_btcm_get_host_dev_info(vm_srv_bt_cm_dev_struct * info)
{
    if (NULL == _vm_btcm_get_host_dev_info)
        _vm_btcm_get_host_dev_info = (_vm_btcm_get_host_dev_info_t)vm_get_sym_entry("vm_btcm_get_host_dev_info");

    if (NULL != _vm_btcm_get_host_dev_info)
        return _vm_btcm_get_host_dev_info(info);

    return (VMINT)-1;
}
