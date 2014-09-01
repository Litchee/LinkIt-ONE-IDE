#include "vmsys.h"
#include "vmthread.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_THREAD_HANDLE (*_vm_thread_get_main_handle_t)(void);
_vm_thread_get_main_handle_t _vm_thread_get_main_handle = NULL;

VM_THREAD_HANDLE vm_thread_get_main_handle(void)
{
    if (NULL == _vm_thread_get_main_handle)
        _vm_thread_get_main_handle = (_vm_thread_get_main_handle_t)vm_get_sym_entry("vm_thread_get_main_handle");
    if (NULL != _vm_thread_get_main_handle)
        return _vm_thread_get_main_handle();
    return 0;
}