#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_rmdir_t)(const VMWSTR dirname);
_vm_file_rmdir_t _vm_file_rmdir = NULL;

VMINT vm_file_rmdir(const VMWSTR dirname)
{
    if (NULL == _vm_file_rmdir)
        _vm_file_rmdir = (_vm_file_rmdir_t)vm_get_sym_entry("vm_file_rmdir");

    if (NULL != _vm_file_rmdir)
        return _vm_file_rmdir(dirname);

    return (VMINT )-1;
}
