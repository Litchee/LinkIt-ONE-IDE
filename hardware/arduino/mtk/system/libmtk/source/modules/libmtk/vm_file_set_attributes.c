#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_set_attributes_t)(const VMWSTR filename, VMBYTE attributes);
_vm_file_set_attributes_t _vm_file_set_attributes = NULL;

VMINT vm_file_set_attributes(const VMWSTR filename, VMBYTE attributes)
{
    if (NULL == _vm_file_set_attributes)
        _vm_file_set_attributes = (_vm_file_set_attributes_t)vm_get_sym_entry("vm_file_set_attributes");

    if (NULL != _vm_file_set_attributes)
        return _vm_file_set_attributes(filename,attributes);

    return (VMINT )-1;
}
