#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_copy_abort_t)(VMINT hdl);
_vm_file_copy_abort_t _vm_file_copy_abort = NULL;

VMINT vm_file_copy_abort(VMINT hdl)
{
    if (NULL == _vm_file_copy_abort)
        _vm_file_copy_abort = (_vm_file_copy_abort_t)vm_get_sym_entry("vm_file_copy_abort");

    if (NULL != _vm_file_copy_abort)
        return _vm_file_copy_abort(hdl);

    return (VMINT )0;
}
