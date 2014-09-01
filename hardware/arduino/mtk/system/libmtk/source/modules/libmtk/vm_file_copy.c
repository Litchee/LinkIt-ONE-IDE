#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_copy_t)(const VMWSTR dst, const VMWSTR src, vm_file_copy_cb cb);
_vm_file_copy_t _vm_file_copy = NULL;

VMINT vm_file_copy(const VMWSTR dst, const VMWSTR src, vm_file_copy_cb cb)
{
    if (NULL == _vm_file_copy)
        _vm_file_copy = (_vm_file_copy_t)vm_get_sym_entry("vm_file_copy");

    if (NULL != _vm_file_copy)
        return _vm_file_copy(dst, src, cb);

    return (VMINT )0;
}
