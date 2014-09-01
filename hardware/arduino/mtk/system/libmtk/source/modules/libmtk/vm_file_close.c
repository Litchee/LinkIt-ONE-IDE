#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_file_close_t)(VMFILE handle);
_vm_file_close_t _vm_file_close = NULL;

void vm_file_close(VMFILE handle)
{
    if (NULL == _vm_file_close)
        _vm_file_close = (_vm_file_close_t)vm_get_sym_entry("vm_file_close");

    if (NULL != _vm_file_close)
        _vm_file_close(handle);

    
}
