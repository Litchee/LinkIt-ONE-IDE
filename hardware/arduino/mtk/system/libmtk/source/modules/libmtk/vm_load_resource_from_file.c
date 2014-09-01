#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8* (*_vm_load_resource_from_file_t)(VMWSTR filename, char *res_name, VMINT *res_size);
_vm_load_resource_from_file_t _vm_load_resource_from_file = NULL;

VMUINT8* vm_load_resource_from_file(VMWSTR filename, char *res_name, VMINT *res_size)
{
    if (NULL == _vm_load_resource_from_file)
        _vm_load_resource_from_file = (_vm_load_resource_from_file_t)vm_get_sym_entry("vm_load_resource_from_file");

    if (NULL != _vm_load_resource_from_file)
        return _vm_load_resource_from_file(filename,res_name,res_size);

    return (VMUINT8* )0;
}
