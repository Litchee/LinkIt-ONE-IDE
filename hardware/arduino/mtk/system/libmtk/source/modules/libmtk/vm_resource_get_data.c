#include "vmsys.h"
#include "vmres.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_resource_get_data_t)(VMUINT8 *data, VMUINT32 offset, VMUINT32 size);
_vm_resource_get_data_t _vm_resource_get_data = NULL;

VMINT32 vm_resource_get_data(VMUINT8 *data, VMUINT32 offset, VMUINT32 size)
{
    if (NULL == _vm_resource_get_data)
        _vm_resource_get_data = (_vm_resource_get_data_t)vm_get_sym_entry("vm_resource_get_data");

    if (NULL != _vm_resource_get_data)
        return _vm_resource_get_data(data,offset,size);

    return (VMINT32 )-1;
}
