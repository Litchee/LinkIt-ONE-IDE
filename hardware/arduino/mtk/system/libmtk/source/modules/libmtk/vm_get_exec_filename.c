#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_exec_filename_t)(VMWSTR filename);
_vm_get_exec_filename_t _vm_get_exec_filename = NULL;

VMINT vm_get_exec_filename(VMWSTR filename)
{
    if (NULL == _vm_get_exec_filename)
        _vm_get_exec_filename = (_vm_get_exec_filename_t)vm_get_sym_entry("vm_get_exec_filename");

    if (NULL != _vm_get_exec_filename)
        return _vm_get_exec_filename(filename);

    return (VMINT )-1;
}
