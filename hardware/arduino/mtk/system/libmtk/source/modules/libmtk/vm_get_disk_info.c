#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_disk_info_t)(const VMCHAR * drv_name, vm_fs_disk_info * fs_disk, vm_fs_di_enum e_di);
_vm_get_disk_info_t _vm_get_disk_info = NULL;

VMINT vm_get_disk_info(const VMCHAR * drv_name, vm_fs_disk_info * fs_disk, vm_fs_di_enum e_di)
{
    if (NULL == _vm_get_disk_info)
        _vm_get_disk_info = (_vm_get_disk_info_t)vm_get_sym_entry("vm_get_disk_info");

    if (NULL != _vm_get_disk_info)
        return _vm_get_disk_info(drv_name,fs_disk,e_di);

    return (VMINT)-1;
}