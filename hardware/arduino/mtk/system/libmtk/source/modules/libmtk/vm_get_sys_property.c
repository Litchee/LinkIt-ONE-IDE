#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_sys_property_t)(const VMINT key, VMCHAR* value, VMUINT len);
_vm_get_sys_property_t _vm_get_sys_property = NULL;

VMUINT vm_get_sys_property(const VMINT key, VMCHAR* value, VMUINT len)
{
    if (NULL == _vm_get_sys_property)
        _vm_get_sys_property = (_vm_get_sys_property_t)vm_get_sym_entry("vm_get_sys_property");

    if (NULL != _vm_get_sys_property)
        return _vm_get_sys_property(key,value,len);

    return (VMUINT )0;
}
