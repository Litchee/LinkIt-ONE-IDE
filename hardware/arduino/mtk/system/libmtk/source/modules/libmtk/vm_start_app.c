#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_start_app_t)(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT flag);
_vm_start_app_t _vm_start_app = NULL;

void vm_start_app(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT flag)
{
    if (NULL == _vm_start_app)
        _vm_start_app = (_vm_start_app_t)vm_get_sym_entry("vm_start_app");

    if (NULL != _vm_start_app)
        _vm_start_app(filepath, parent_app_handle, flag);
}
