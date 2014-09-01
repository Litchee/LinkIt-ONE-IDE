#include "vmsys.h"
#include "vmappcomm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_appcomm_send_msg_t)(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam);
_vm_appcomm_send_msg_t _vm_appcomm_send_msg = NULL;

VMINT vm_appcomm_send_msg(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
    if (NULL == _vm_appcomm_send_msg)
        _vm_appcomm_send_msg = (_vm_appcomm_send_msg_t)vm_get_sym_entry("vm_appcomm_send_msg");

    if (NULL != _vm_appcomm_send_msg)
        return _vm_appcomm_send_msg(handle,msg_id,wparam,lparam);

    return (VMINT )-1;
}
