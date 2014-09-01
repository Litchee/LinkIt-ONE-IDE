#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_get_attributes_t)(const VMWSTR filename);
_vm_file_get_attributes_t _vm_file_get_attributes = NULL;

VMINT vm_file_get_attributes(const VMWSTR filename)
{
    if (NULL == _vm_file_get_attributes)
        _vm_file_get_attributes = (_vm_file_get_attributes_t)vm_get_sym_entry("vm_file_get_attributes");

    if (NULL != _vm_file_get_attributes)
        return _vm_file_get_attributes(filename);

    return (VMINT )-1;
}
