#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_storage_close_t)(VMINT h);
_vm_storage_close_t _vm_storage_close = NULL;

void vm_storage_close(VMINT h)
{
    if (NULL == _vm_storage_close)
        _vm_storage_close = (_vm_storage_close_t)vm_get_sym_entry("vm_storage_close");

    if (NULL != _vm_storage_close)
        _vm_storage_close(h);

    
}
