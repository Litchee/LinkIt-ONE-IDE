#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_fs_async_open_t)(const VMWSTR file_name, VMINT flag, vm_fs_overlapped_struct *overlapped);
_vm_fs_async_open_t _vm_fs_async_open = NULL;

VMINT vm_fs_async_open(const VMWSTR file_name, VMINT flag, vm_fs_overlapped_struct *overlapped)
{
    if (NULL == _vm_fs_async_open)
        _vm_fs_async_open = (_vm_fs_async_open_t)vm_get_sym_entry("vm_fs_async_open");

    if (NULL != _vm_fs_async_open)
        return _vm_fs_async_open(file_name,flag,overlapped);

    return (VMINT)-1;
}