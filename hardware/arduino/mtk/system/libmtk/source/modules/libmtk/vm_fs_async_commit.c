#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_commit_t)(VM_FS_HANDLE fs_hdl);
_vm_fs_async_commit_t _vm_fs_async_commit = NULL;

VMINT vm_fs_async_commit(VM_FS_HANDLE fs_hdl)
{
    if (NULL == _vm_fs_async_commit)
        _vm_fs_async_commit = (_vm_fs_async_commit_t)vm_get_sym_entry("vm_fs_async_commit");

    if (NULL != _vm_fs_async_commit)
        return _vm_fs_async_commit(fs_hdl);

    return (VMINT)-1;
}