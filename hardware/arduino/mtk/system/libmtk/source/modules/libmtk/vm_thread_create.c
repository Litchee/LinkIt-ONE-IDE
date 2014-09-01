#include "vmsys.h"
#include "vmthread.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_THREAD_HANDLE (*_vm_thread_create_t)(VM_THREAD_FUNC thread_function, void* data,VMUINT8 priority);
_vm_thread_create_t _vm_thread_create = NULL;

VM_THREAD_HANDLE vm_thread_create(VM_THREAD_FUNC thread_function, void* data,VMUINT8 priority)
{
    if (NULL == _vm_thread_create)
        _vm_thread_create = (_vm_thread_create_t)vm_get_sym_entry("vm_thread_create");
    if (NULL != _vm_thread_create)
        return _vm_thread_create(thread_function,data,priority);
    return 0;
}