#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_storage_open_t)(void);
_vm_storage_open_t _vm_storage_open = NULL;

VMINT vm_storage_open(void)
{
    if (NULL == _vm_storage_open)
        _vm_storage_open = (_vm_storage_open_t)vm_get_sym_entry("vm_storage_open");

    if (NULL != _vm_storage_open)
        return _vm_storage_open();

    return (VMINT )-1;
}
