#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_set_ctx_t)(VM_P_HANDLE p_handle);
_vm_pmng_set_ctx_t _vm_pmng_set_ctx = NULL;

VMINT vm_pmng_set_ctx(VM_P_HANDLE p_handle)
{
    if (NULL == _vm_pmng_set_ctx)
        _vm_pmng_set_ctx = (_vm_pmng_set_ctx_t)vm_get_sym_entry("vm_pmng_set_ctx");

    if (NULL != _vm_pmng_set_ctx)
        return _vm_pmng_set_ctx(p_handle);

    return -1;
}