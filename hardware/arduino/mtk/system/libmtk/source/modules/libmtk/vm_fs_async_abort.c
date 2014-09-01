#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_abort_t)(vm_fs_job_id jid);
_vm_fs_async_abort_t _vm_fs_async_abort = NULL;

VMINT vm_fs_async_abort(vm_fs_job_id jid)
{
    if (NULL == _vm_fs_async_abort)
        _vm_fs_async_abort = (_vm_fs_async_abort_t)vm_get_sym_entry("vm_fs_async_abort");

    if (NULL != _vm_fs_async_abort)
        return _vm_fs_async_abort(jid);

    return (VMINT)-1;
}