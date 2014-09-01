#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_provider_count_t)(void);
_vm_sso_get_provider_count_t _vm_sso_get_provider_count = NULL;

VMINT vm_sso_get_provider_count(void)
{
    if (NULL == _vm_sso_get_provider_count)
        _vm_sso_get_provider_count = (_vm_sso_get_provider_count_t)vm_get_sym_entry("vm_sso_get_provider_count");

    if (NULL != _vm_sso_get_provider_count)
        return _vm_sso_get_provider_count();

    return (VMINT)-1;
}