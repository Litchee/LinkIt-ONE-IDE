#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_write_t)(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *written, vm_fs_overlapped_struct *overlapped);
_vm_fs_async_write_t _vm_fs_async_write = NULL;

VMINT vm_fs_async_write(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *written, vm_fs_overlapped_struct *overlapped)
{
    if (NULL == _vm_fs_async_write)
        _vm_fs_async_write = (_vm_fs_async_write_t)vm_get_sym_entry("vm_fs_async_write");

    if (NULL != _vm_fs_async_write)
        return _vm_fs_async_write(fs_hdl,data,length,written,overlapped);

    return (VMINT)-1;
}