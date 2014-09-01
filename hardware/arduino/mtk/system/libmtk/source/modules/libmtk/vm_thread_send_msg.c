#include "vmsys.h"
#include "vmthread.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_thread_send_msg_t)(VM_THREAD_HANDLE thread_handle, VMUINT32 msg_id, void* user_data);
_vm_thread_send_msg_t _vm_thread_send_msg = NULL;

void vm_thread_send_msg(VM_THREAD_HANDLE thread_handle, VMUINT32 msg_id, void* user_data)
{
    if (NULL == _vm_thread_send_msg)
        _vm_thread_send_msg = (_vm_thread_send_msg_t)vm_get_sym_entry("vm_thread_send_msg");
    if (NULL != _vm_thread_send_msg)
        _vm_thread_send_msg(thread_handle,msg_id,user_data);
}