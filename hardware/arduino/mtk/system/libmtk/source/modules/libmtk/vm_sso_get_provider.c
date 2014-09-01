#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_provider_t)(VMUINT32 provider, vm_sso_provider_struct * buffer);
_vm_sso_get_provider_t _vm_sso_get_provider = NULL;

VMINT vm_sso_get_provider(VMUINT32 provider, vm_sso_provider_struct * buffer)
{
    if (NULL == _vm_sso_get_provider)
        _vm_sso_get_provider = (_vm_sso_get_provider_t)vm_get_sym_entry("vm_sso_get_provider");

    if (NULL != _vm_sso_get_provider)
        return _vm_sso_get_provider(provider,buffer);

    return (VMINT)-1;
}