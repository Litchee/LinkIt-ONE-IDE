#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_send_msg_t)(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam);
_vm_send_msg_t _vm_send_msg = NULL;

VMINT vm_send_msg(VM_P_HANDLE phandle, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
    if (NULL == _vm_send_msg)
        _vm_send_msg = (_vm_send_msg_t)vm_get_sym_entry("vm_send_msg");

    if (NULL != _vm_send_msg)
        return _vm_send_msg(phandle,msg_id,wparam,lparam);

    return (VMINT )-1;
}
