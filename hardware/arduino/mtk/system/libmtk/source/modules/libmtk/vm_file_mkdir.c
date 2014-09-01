#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_mkdir_t)(const VMWSTR dirname);
_vm_file_mkdir_t _vm_file_mkdir = NULL;

VMINT vm_file_mkdir(const VMWSTR dirname)
{
    if (NULL == _vm_file_mkdir)
        _vm_file_mkdir = (_vm_file_mkdir_t)vm_get_sym_entry("vm_file_mkdir");

    if (NULL != _vm_file_mkdir)
        return _vm_file_mkdir(dirname);

    return (VMINT )-1;
}
