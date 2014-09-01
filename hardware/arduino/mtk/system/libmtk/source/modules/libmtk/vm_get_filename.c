#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_get_filename_t)(VMWSTR path, VMWSTR filename);
_vm_get_filename_t _vm_get_filename = NULL;

void vm_get_filename(VMWSTR path, VMWSTR filename)
{
    if (NULL == _vm_get_filename)
        _vm_get_filename = (_vm_get_filename_t)vm_get_sym_entry("vm_get_filename");

    if (NULL != _vm_get_filename)
        _vm_get_filename(path,filename);

    
}
