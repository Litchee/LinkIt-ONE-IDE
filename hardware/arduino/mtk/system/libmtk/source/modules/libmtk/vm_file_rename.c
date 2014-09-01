#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_rename_t)(const VMWSTR filename, const VMWSTR newname);
_vm_file_rename_t _vm_file_rename = NULL;

VMINT vm_file_rename(const VMWSTR filename, const VMWSTR newname)
{
    if (NULL == _vm_file_rename)
        _vm_file_rename = (_vm_file_rename_t)vm_get_sym_entry("vm_file_rename");

    if (NULL != _vm_file_rename)
        return _vm_file_rename(filename,newname);

    return (VMINT )-1;
}
