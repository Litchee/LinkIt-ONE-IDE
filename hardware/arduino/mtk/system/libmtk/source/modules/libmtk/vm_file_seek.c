#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_seek_t)(VMFILE handle, VMINT offset, VMINT base);
_vm_file_seek_t _vm_file_seek = NULL;

VMINT vm_file_seek(VMFILE handle, VMINT offset, VMINT base)
{
    if (NULL == _vm_file_seek)
        _vm_file_seek = (_vm_file_seek_t)vm_get_sym_entry("vm_file_seek");

    if (NULL != _vm_file_seek)
        return _vm_file_seek(handle,offset,base);

    return (VMINT )-1;
}
