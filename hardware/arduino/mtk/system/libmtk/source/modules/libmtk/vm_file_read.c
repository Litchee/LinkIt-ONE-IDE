#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_read_t)(VMFILE handle, void * data, VMUINT length, VMUINT *nread);
_vm_file_read_t _vm_file_read = NULL;

VMINT vm_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread)
{
    if (NULL == _vm_file_read)
        _vm_file_read = (_vm_file_read_t)vm_get_sym_entry("vm_file_read");

    if (NULL != _vm_file_read)
        return _vm_file_read(handle,data,length,nread);

    return (VMINT )-1;
}
