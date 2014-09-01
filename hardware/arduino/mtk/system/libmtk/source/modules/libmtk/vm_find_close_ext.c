#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_find_close_ext_t)(VMINT handle);
_vm_find_close_ext_t _vm_find_close_ext = NULL;

void vm_find_close_ext(VMINT handle)
{
    if (NULL == _vm_find_close_ext)
        _vm_find_close_ext = (_vm_find_close_ext_t)vm_get_sym_entry("vm_find_close_ext");

    if (NULL != _vm_find_close_ext)
        _vm_find_close_ext(handle);

    
}
