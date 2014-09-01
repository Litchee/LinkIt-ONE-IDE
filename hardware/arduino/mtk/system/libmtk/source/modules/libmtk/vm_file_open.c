#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMFILE (*_vm_file_open_t)(const VMWSTR filename, VMUINT mode, VMUINT binary);
_vm_file_open_t _vm_file_open = NULL;

VMFILE vm_file_open(const VMWSTR filename, VMUINT mode, VMUINT binary)
{
    if (NULL == _vm_file_open)
        _vm_file_open = (_vm_file_open_t)vm_get_sym_entry("vm_file_open");

    if (NULL != _vm_file_open)
        return _vm_file_open(filename,mode,binary);

    return (VMFILE )-1;
}
