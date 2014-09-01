#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_seek_t)(VM_FS_HANDLE fs_hdl, VMINT64 * offset, VMINT whence, vm_fs_overlapped_struct *overlapped);
_vm_fs_async_seek_t _vm_fs_async_seek = NULL;

VMINT vm_fs_async_seek(VM_FS_HANDLE fs_hdl, VMINT64 * offset, VMINT whence, vm_fs_overlapped_struct *overlapped)
{
    if (NULL == _vm_fs_async_seek)
        _vm_fs_async_seek = (_vm_fs_async_seek_t)vm_get_sym_entry("vm_fs_async_seek");

    if (NULL != _vm_fs_async_seek)
        return _vm_fs_async_seek(fs_hdl,offset,whence,overlapped);

    return (VMINT)-1;
}