#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_tmp_filename_t)(char* prefix, char* filename);
_vm_tmp_filename_t _vm_tmp_filename = NULL;

void vm_tmp_filename(char* prefix, char* filename)
{
    if (NULL == _vm_tmp_filename)
        _vm_tmp_filename = (_vm_tmp_filename_t)vm_get_sym_entry("vm_tmp_filename");

    if (NULL != _vm_tmp_filename)
        _vm_tmp_filename(prefix,filename);

    
}
