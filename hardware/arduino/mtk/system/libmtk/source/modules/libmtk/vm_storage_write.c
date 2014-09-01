#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_storage_write_t)(VMINT h, const void * data, VMUINT offset, VMUINT size, VMUINT * written);
_vm_storage_write_t _vm_storage_write = NULL;

VMINT vm_storage_write(VMINT h, const void * data, VMUINT offset, VMUINT size, VMUINT * written)
{
    if (NULL == _vm_storage_write)
        _vm_storage_write = (_vm_storage_write_t)vm_get_sym_entry("vm_storage_write");

    if (NULL != _vm_storage_write)
        return _vm_storage_write(h,data,offset,size,written);

    return (VMINT )-1;
}
