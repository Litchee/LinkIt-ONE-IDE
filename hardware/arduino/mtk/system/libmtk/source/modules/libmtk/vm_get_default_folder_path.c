#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef const VMWCHAR * (*_vm_get_default_folder_path_t)(vm_fmgr_default_folder_enum type);
_vm_get_default_folder_path_t _vm_get_default_folder_path = NULL;

const VMWCHAR * vm_get_default_folder_path(vm_fmgr_default_folder_enum type)
{
    if (NULL == _vm_get_default_folder_path)
        _vm_get_default_folder_path = (_vm_get_default_folder_path_t)vm_get_sym_entry("vm_get_default_folder_path");

    if (NULL != _vm_get_default_folder_path)
        return _vm_get_default_folder_path(type);
		return NULL;
}
