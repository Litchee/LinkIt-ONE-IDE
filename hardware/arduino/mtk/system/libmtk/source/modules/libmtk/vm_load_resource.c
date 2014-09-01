#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8* (*_vm_load_resource_t)(char* res_name, VMINT* res_size);
_vm_load_resource_t _vm_load_resource = NULL;

VMUINT8* vm_load_resource(char* res_name, VMINT* res_size)
{
    if (NULL == _vm_load_resource)
        _vm_load_resource = (_vm_load_resource_t)vm_get_sym_entry("vm_load_resource");

    if (NULL != _vm_load_resource)
        return _vm_load_resource(res_name,res_size);

    return (VMUINT8* )0;
}
