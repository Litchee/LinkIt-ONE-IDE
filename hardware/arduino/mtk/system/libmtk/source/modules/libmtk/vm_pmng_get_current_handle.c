#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_P_HANDLE (*_vm_pmng_get_current_handle_t)(void);
_vm_pmng_get_current_handle_t _vm_pmng_get_current_handle = NULL;

VM_P_HANDLE vm_pmng_get_current_handle(void)
{
    VM_P_HANDLE  ret = {-1};
    if (NULL == _vm_pmng_get_current_handle)
        _vm_pmng_get_current_handle = (_vm_pmng_get_current_handle_t)vm_get_sym_entry("vm_pmng_get_current_handle");

    if (NULL != _vm_pmng_get_current_handle)
        return _vm_pmng_get_current_handle();

    return ret;
}
