#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_provider_name_t)(VMUINT32 provider, VMWCHAR * buffer);
_vm_sso_get_provider_name_t _vm_sso_get_provider_name = NULL;

VMINT vm_sso_get_provider_name(VMUINT32 provider, VMWCHAR * buffer)
{
    if (NULL == _vm_sso_get_provider_name)
        _vm_sso_get_provider_name = (_vm_sso_get_provider_name_t)vm_get_sym_entry("vm_sso_get_provider_name");

    if (NULL != _vm_sso_get_provider_name)
        return _vm_sso_get_provider_name(provider,buffer);

    return (VMINT)-1;
}