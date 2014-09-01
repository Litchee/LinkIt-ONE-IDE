#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_delete_t)(const VMWSTR filename, vm_fs_overlapped_struct *overlapped);
_vm_fs_async_delete_t _vm_fs_async_delete = NULL;

VMINT vm_fs_async_delete(const VMWSTR filename, vm_fs_overlapped_struct *overlapped)
{
    if (NULL == _vm_fs_async_delete)
        _vm_fs_async_delete = (_vm_fs_async_delete_t)vm_get_sym_entry("vm_fs_async_delete");

    if (NULL != _vm_fs_async_delete)
        return _vm_fs_async_delete(filename,overlapped);

    return (VMINT)-1;
}