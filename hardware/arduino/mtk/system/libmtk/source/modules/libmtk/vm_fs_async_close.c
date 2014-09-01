#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_close_t)(VM_FS_HANDLE fs_hdl);
_vm_fs_async_close_t _vm_fs_async_close = NULL;

VMINT vm_fs_async_close(VM_FS_HANDLE fs_hdl)
{
    if (NULL == _vm_fs_async_close)
        _vm_fs_async_close = (_vm_fs_async_close_t)vm_get_sym_entry("vm_fs_async_close");

    if (NULL != _vm_fs_async_close)
        return _vm_fs_async_close(fs_hdl);

    return (VMINT)-1;
}