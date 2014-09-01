#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_P_HANDLE (*_vm_pmng_get_handle_t)(VMWSTR file_name);
_vm_pmng_get_handle_t _vm_pmng_get_handle = NULL;

VM_P_HANDLE vm_pmng_get_handle(VMWSTR file_name)
{
    VM_P_HANDLE  ret = {-1};
    if (NULL == _vm_pmng_get_handle)
        _vm_pmng_get_handle = (_vm_pmng_get_handle_t)vm_get_sym_entry("vm_pmng_get_handle");

    if (NULL != _vm_pmng_get_handle)
        return _vm_pmng_get_handle(file_name);

    return ret;
}
