#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_get_app_handle_t)(void);
_vm_pmng_get_app_handle_t _vm_pmng_get_app_handle = NULL;

VMINT vm_pmng_get_app_handle(void)
{
    if (NULL == _vm_pmng_get_app_handle)
        _vm_pmng_get_app_handle = (_vm_pmng_get_app_handle_t)vm_get_sym_entry("vm_pmng_get_app_handle");

    if (NULL != _vm_pmng_get_app_handle)
        return _vm_pmng_get_app_handle();

    return 0;
}
