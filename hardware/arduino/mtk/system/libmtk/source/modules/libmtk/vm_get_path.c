#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_path_t)(VMWSTR fullpath, VMWSTR path);
_vm_get_path_t _vm_get_path = NULL;

VMINT vm_get_path(VMWSTR fullpath, VMWSTR path)
{
    if (NULL == _vm_get_path)
        _vm_get_path = (_vm_get_path_t)vm_get_sym_entry("vm_get_path");

    if (NULL != _vm_get_path)
        return _vm_get_path(fullpath,path);

    return (VMINT )-1;
}
