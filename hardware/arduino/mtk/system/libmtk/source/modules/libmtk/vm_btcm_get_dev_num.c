#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_get_dev_num_t)(vm_srv_bt_cm_dev_type_enum dev_type);
_vm_btcm_get_dev_num_t _vm_btcm_get_dev_num = NULL;
VMINT vm_btcm_get_dev_num(vm_srv_bt_cm_dev_type_enum dev_type)
{
    if (NULL == _vm_btcm_get_dev_num)
        _vm_btcm_get_dev_num = (_vm_btcm_get_dev_num_t)vm_get_sym_entry("vm_btcm_get_dev_num");

    if (NULL != _vm_btcm_get_dev_num)
        return _vm_btcm_get_dev_num(dev_type);

    return (VMINT)-1;
}
