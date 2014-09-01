#include "vmsys.h"
#include "vmthread.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_thread_get_msg_t)(VM_MSG_STRUCT* msg);
_vm_thread_get_msg_t _vm_thread_get_msg = NULL;

void vm_thread_get_msg(VM_MSG_STRUCT* msg)
{
    if (NULL == _vm_thread_get_msg)
        _vm_thread_get_msg = (_vm_thread_get_msg_t)vm_get_sym_entry("vm_thread_get_msg");
    if (NULL != _vm_thread_get_msg)
        _vm_thread_get_msg(msg);
}