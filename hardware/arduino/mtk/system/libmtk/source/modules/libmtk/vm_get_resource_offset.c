#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_resource_offset_t)(char* res_name);
_vm_get_resource_offset_t _vm_get_resource_offset = NULL;

VMUINT vm_get_resource_offset(char *res_name)
{
    if (NULL == _vm_get_resource_offset)
        _vm_get_resource_offset = (_vm_get_resource_offset_t)vm_get_sym_entry("vm_get_resource_offset");

    if (NULL != _vm_get_resource_offset)
        return _vm_get_resource_offset(res_name);

    return 0;
}
