#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_reg_msg_proc_t)(VM_MESSAGE_PROC proc);
_vm_reg_msg_proc_t _vm_reg_msg_proc = NULL;

void vm_reg_msg_proc(VM_MESSAGE_PROC proc)
{
    if (NULL == _vm_reg_msg_proc)
        _vm_reg_msg_proc = (_vm_reg_msg_proc_t)vm_get_sym_entry("vm_reg_msg_proc");

    if (NULL != _vm_reg_msg_proc)
        _vm_reg_msg_proc(proc);

    
}
