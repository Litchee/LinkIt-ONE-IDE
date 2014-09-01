#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_resource_offset_from_file_t)(VMWSTR filename, char *res_name);
_vm_get_resource_offset_from_file_t _vm_get_resource_offset_from_file = NULL;

VMUINT vm_get_resource_offset_from_file(VMWSTR filename, char *res_name)
{
    if (NULL == _vm_get_resource_offset_from_file)
        _vm_get_resource_offset_from_file = (_vm_get_resource_offset_from_file_t)vm_get_sym_entry("vm_get_resource_offset_from_file");

    if (NULL != _vm_get_resource_offset_from_file)
        return _vm_get_resource_offset_from_file(filename, res_name);

    return 0;
}
