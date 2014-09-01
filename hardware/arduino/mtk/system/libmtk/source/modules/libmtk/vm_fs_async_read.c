#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_read_t)(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *read, vm_fs_overlapped_struct *overlapped);
_vm_fs_async_read_t _vm_fs_async_read = NULL;

VMINT vm_fs_async_read(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *read, vm_fs_overlapped_struct *overlapped)
{
    if (NULL == _vm_fs_async_read)
        _vm_fs_async_read = (_vm_fs_async_read_t)vm_get_sym_entry("vm_fs_async_read");

    if (NULL != _vm_fs_async_read)
        return _vm_fs_async_read(fs_hdl,data,length,read,overlapped);

    return (VMINT)-1;
}