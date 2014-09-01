#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_start_app_with_para_t)(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT is_parent_exit,void* parameter,VMINT parameter_size);
_vm_start_app_with_para_t _vm_start_app_with_para = NULL;

void vm_start_app_with_para(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT is_parent_exit,void* parameter,VMINT parameter_size)
{
    if (NULL == _vm_start_app_with_para)
        _vm_start_app_with_para = (_vm_start_app_with_para_t)vm_get_sym_entry("vm_start_app_with_para");

    if (NULL != _vm_start_app_with_para)
        _vm_start_app_with_para(filepath, parent_app_handle, is_parent_exit, parameter, parameter_size);
}

