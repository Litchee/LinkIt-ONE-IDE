#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_file_is_eof_t)(VMFILE handle);
_vm_file_is_eof_t _vm_file_is_eof = NULL;

VMINT vm_file_is_eof(VMFILE handle)
{
    if (NULL == _vm_file_is_eof)
        _vm_file_is_eof = (_vm_file_is_eof_t)vm_get_sym_entry("vm_file_is_eof");

    if (NULL != _vm_file_is_eof)
        return _vm_file_is_eof(handle);

    return (VMINT )-1;
}
