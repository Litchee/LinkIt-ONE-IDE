#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_find_close_t)(VMINT handle);
_vm_find_close_t _vm_find_close = NULL;

void vm_find_close(VMINT handle)
{
    if (NULL == _vm_find_close)
        _vm_find_close = (_vm_find_close_t)vm_get_sym_entry("vm_find_close");

    if (NULL != _vm_find_close)
        _vm_find_close(handle);

    
}
