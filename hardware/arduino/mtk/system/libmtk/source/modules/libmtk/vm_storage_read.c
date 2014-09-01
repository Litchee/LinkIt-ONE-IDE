#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_storage_read_t)(VMINT h, void * data, VMUINT offset, VMUINT size, VMUINT * read);
_vm_storage_read_t _vm_storage_read = NULL;

VMINT vm_storage_read(VMINT h, void * data, VMUINT offset, VMUINT size, VMUINT * read)
{
    if (NULL == _vm_storage_read)
        _vm_storage_read = (_vm_storage_read_t)vm_get_sym_entry("vm_storage_read");

    if (NULL != _vm_storage_read)
        return _vm_storage_read(h,data,offset,size,read);

    return (VMINT )-1;
}
