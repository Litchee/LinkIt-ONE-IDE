#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_resource_get_data_from_file_t)(VMWSTR filename, VMUINT8 *data, VMUINT32 offset, VMUINT32 size);
_vm_resource_get_data_from_file_t _vm_resource_get_data_from_file = NULL;

VMINT32 vm_resource_get_data_from_file(VMWSTR filename, VMUINT8 *data, VMUINT32 offset, VMUINT32 size)
{
    if (NULL == _vm_resource_get_data_from_file)
        _vm_resource_get_data_from_file = (_vm_resource_get_data_from_file_t)vm_get_sym_entry("vm_resource_get_data_from_file");

    if (NULL != _vm_resource_get_data_from_file)
        return _vm_resource_get_data_from_file(filename, data,offset,size);

    return (VMINT32 )-1;
}
