#include "vmsys.h"
#include "vmbtnotify.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_bt_noti_check_channel_valid_t)(VMINT cntx_chnl);
_vm_bt_noti_check_channel_valid_t _vm_bt_noti_check_channel_valid = NULL;

VMINT vm_bt_noti_check_channel_valid(VMINT cntx_chnl)
{
    if (NULL == _vm_bt_noti_check_channel_valid)
        _vm_bt_noti_check_channel_valid = (_vm_bt_noti_check_channel_valid_t)vm_get_sym_entry("vm_bt_noti_check_channel_valid");
    if (NULL != _vm_bt_noti_check_channel_valid)
        return _vm_bt_noti_check_channel_valid(cntx_chnl);
    return (VMINT)-1;
}