#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_get_disk_free_space_t)(VMWSTR drv_name);
_vm_get_disk_free_space_t _vm_get_disk_free_space = NULL;

VMUINT vm_get_disk_free_space(VMWSTR drv_name)
{
    if (NULL == _vm_get_disk_free_space)
        _vm_get_disk_free_space = (_vm_get_disk_free_space_t)vm_get_sym_entry("vm_get_disk_free_space");

    if (NULL != _vm_get_disk_free_space)
        return _vm_get_disk_free_space(drv_name);

    return (VMUINT )0;
}
