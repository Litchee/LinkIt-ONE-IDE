#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_reset_ctx_t)(void);
_vm_pmng_reset_ctx_t _vm_pmng_reset_ctx = NULL;

VMINT vm_pmng_reset_ctx(void)
{
    if (NULL == _vm_pmng_reset_ctx)
        _vm_pmng_reset_ctx = (_vm_pmng_reset_ctx_t)vm_get_sym_entry("vm_pmng_reset_ctx");

    if (NULL != _vm_pmng_reset_ctx)
        return _vm_pmng_reset_ctx();

    return -1;
}
