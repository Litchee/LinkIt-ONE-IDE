#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_delete_t)(const VMWSTR filename);
_vm_file_delete_t _vm_file_delete = NULL;

VMINT vm_file_delete(const VMWSTR filename)
{
    if (NULL == _vm_file_delete)
        _vm_file_delete = (_vm_file_delete_t)vm_get_sym_entry("vm_file_delete");

    if (NULL != _vm_file_delete)
        return _vm_file_delete(filename);

    return (VMINT )-1;
}
