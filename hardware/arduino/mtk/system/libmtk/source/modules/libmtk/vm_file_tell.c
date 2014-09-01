#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_tell_t)(VMFILE handle);
_vm_file_tell_t _vm_file_tell = NULL;

VMINT vm_file_tell(VMFILE handle)
{
    if (NULL == _vm_file_tell)
        _vm_file_tell = (_vm_file_tell_t)vm_get_sym_entry("vm_file_tell");

    if (NULL != _vm_file_tell)
        return _vm_file_tell(handle);

    return (VMINT )-1;
}
