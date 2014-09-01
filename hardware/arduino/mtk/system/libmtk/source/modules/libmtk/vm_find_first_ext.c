#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_find_first_ext_t)(VMWSTR pathname, vm_fileinfo_ext * direntry);
_vm_find_first_ext_t _vm_find_first_ext = NULL;

VMINT vm_find_first_ext(VMWSTR pathname, vm_fileinfo_ext * direntry)
{
    if (NULL == _vm_find_first_ext)
        _vm_find_first_ext = (_vm_find_first_ext_t)vm_get_sym_entry("vm_find_first_ext");

    if (NULL != _vm_find_first_ext)
        return _vm_find_first_ext(pathname,direntry);

    return (VMINT )-1;
}
