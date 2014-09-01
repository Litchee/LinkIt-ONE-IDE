#include "vmsys.h"
#include "vmpromng.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pmng_set_bg_t)(void);
_vm_pmng_set_bg_t _vm_pmng_set_bg = NULL;

VMINT vm_pmng_set_bg(void)
{
    if (NULL == _vm_pmng_set_bg)
        _vm_pmng_set_bg = (_vm_pmng_set_bg_t)vm_get_sym_entry("vm_pmng_set_bg");

    if (NULL != _vm_pmng_set_bg)
        return _vm_pmng_set_bg();

    return (VMINT )-1;
}
