#include "vmsys.h"
#include "vmappcomm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_appcomm_reg_msg_proc_t)(VMINT handle, VM_MESSAGE_PROC proc);
_vm_appcomm_reg_msg_proc_t _vm_appcomm_reg_msg_proc = NULL;

VMINT vm_appcomm_reg_msg_proc(VMINT handle, VM_MESSAGE_PROC proc)
{
    if (NULL == _vm_appcomm_reg_msg_proc)
        _vm_appcomm_reg_msg_proc = (_vm_appcomm_reg_msg_proc_t)vm_get_sym_entry("vm_appcomm_reg_msg_proc");

    if (NULL != _vm_appcomm_reg_msg_proc)
        return _vm_appcomm_reg_msg_proc(handle,proc);

    return (VMINT )-1;
}
