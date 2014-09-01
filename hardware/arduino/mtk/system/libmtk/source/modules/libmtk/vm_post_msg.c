#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_post_msg_t)(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam);
_vm_post_msg_t _vm_post_msg = NULL;

VMINT vm_post_msg(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
    if (NULL == _vm_post_msg)
        _vm_post_msg = (_vm_post_msg_t)vm_get_sym_entry("vm_post_msg");

    if (NULL != _vm_post_msg)
        return _vm_post_msg(phandle,msg_id,wparam,lparam);

    return (VMINT )-1;
}
