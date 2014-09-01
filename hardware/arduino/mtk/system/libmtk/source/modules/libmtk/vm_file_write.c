#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_write_t)(VMFILE handle, void * data, VMUINT length, VMUINT * written);
_vm_file_write_t _vm_file_write = NULL;

VMINT vm_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written)
{
    if (NULL == _vm_file_write)
        _vm_file_write = (_vm_file_write_t)vm_get_sym_entry("vm_file_write");

    if (NULL != _vm_file_write)
        return _vm_file_write(handle,data,length,written);

    return (VMINT )-1;
}
