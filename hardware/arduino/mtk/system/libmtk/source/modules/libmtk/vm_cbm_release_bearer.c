#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_cbm_release_bearer_t)(void);
_vm_cbm_release_bearer_t _vm_cbm_release_bearer = NULL;

VMINT vm_cbm_release_bearer(void)
{
    if (NULL == _vm_cbm_release_bearer)
        _vm_cbm_release_bearer = (_vm_cbm_release_bearer_t)vm_get_sym_entry("vm_cbm_release_bearer");

    if (NULL != _vm_cbm_release_bearer)
        return _vm_cbm_release_bearer();

    return (VMINT)-1;
}