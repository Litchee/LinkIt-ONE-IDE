#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_get_dev_info_by_index_t)(VMUINT idx, vm_srv_bt_cm_dev_type_enum dev_type, vm_srv_bt_cm_dev_struct * info);
_vm_btcm_get_dev_info_by_index_t _vm_btcm_get_dev_info_by_index = NULL;
VMINT vm_btcm_get_dev_info_by_index(VMUINT idx, vm_srv_bt_cm_dev_type_enum dev_type, vm_srv_bt_cm_dev_struct * info)
{
    if (NULL == _vm_btcm_get_dev_info_by_index)
        _vm_btcm_get_dev_info_by_index = (_vm_btcm_get_dev_info_by_index_t)vm_get_sym_entry("vm_btcm_get_dev_info_by_index");

    if (NULL != _vm_btcm_get_dev_info_by_index)
        return _vm_btcm_get_dev_info_by_index(idx,dev_type,info);

    return (VMINT)-1;
}
