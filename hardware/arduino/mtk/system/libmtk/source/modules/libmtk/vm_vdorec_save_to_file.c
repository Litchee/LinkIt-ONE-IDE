#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_vdorec_save_to_file_t)(VMWSTR filepath, vm_vdorec_callback callback);
_vm_vdorec_save_to_file_t _vm_vdorec_save_to_file = NULL;

void vm_vdorec_save_to_file(VMWSTR filepath, vm_vdorec_callback callback)
{
    if (NULL == _vm_vdorec_save_to_file)
        _vm_vdorec_save_to_file = (_vm_vdorec_save_to_file_t)vm_get_sym_entry("vm_vdorec_save_to_file");

    if (NULL != _vm_vdorec_save_to_file)
        _vm_vdorec_save_to_file(filepath,callback);
}
