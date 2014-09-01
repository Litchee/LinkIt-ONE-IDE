#include "vmsys.h"
#include "vmappcomm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_appcomm_post_msg_t)(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam);
_vm_appcomm_post_msg_t _vm_appcomm_post_msg = NULL;

VMINT vm_appcomm_post_msg(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
    if (NULL == _vm_appcomm_post_msg)
        _vm_appcomm_post_msg = (_vm_appcomm_post_msg_t)vm_get_sym_entry("vm_appcomm_post_msg");

    if (NULL != _vm_appcomm_post_msg)
        return _vm_appcomm_post_msg(handle,msg_id,wparam,lparam);

    return (VMINT )-1;
}
