#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_commit_t)(VMFILE handle);
_vm_file_commit_t _vm_file_commit = NULL;

VMINT vm_file_commit(VMFILE handle)
{
    if (NULL == _vm_file_commit)
        _vm_file_commit = (_vm_file_commit_t)vm_get_sym_entry("vm_file_commit");

    if (NULL != _vm_file_commit)
        return _vm_file_commit(handle);

    return (VMINT )-1;
}
