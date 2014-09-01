#include "vmsys.h"
#include "vmbtcm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btcm_srv_set_visibility_t)(vm_srv_bt_cm_visibility_type type);
_vm_btcm_srv_set_visibility_t _vm_btcm_srv_set_visibility = NULL;
VMINT vm_btcm_srv_set_visibility(vm_srv_bt_cm_visibility_type type)
{
    if (NULL == _vm_btcm_srv_set_visibility)
        _vm_btcm_srv_set_visibility = (_vm_btcm_srv_set_visibility_t)vm_get_sym_entry("vm_btcm_srv_set_visibility");

    if (NULL != _vm_btcm_srv_set_visibility)
        return _vm_btcm_srv_set_visibility(type);

    return (VMINT)-1;
}
