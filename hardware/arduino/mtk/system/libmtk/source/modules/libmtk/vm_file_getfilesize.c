#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_getfilesize_t)(VMFILE handle, VMUINT *file_size);
_vm_file_getfilesize_t _vm_file_getfilesize = NULL;

VMINT vm_file_getfilesize(VMFILE handle, VMUINT *file_size)
{
    if (NULL == _vm_file_getfilesize)
        _vm_file_getfilesize = (_vm_file_getfilesize_t)vm_get_sym_entry("vm_file_getfilesize");

    if (NULL != _vm_file_getfilesize)
        return _vm_file_getfilesize(handle,file_size);

    return (VMINT )-1;
}
