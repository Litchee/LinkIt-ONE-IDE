#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_providers_t)(vm_sso_provider_struct * buffer, VMUINT8 buffer_items);
_vm_sso_get_providers_t _vm_sso_get_providers = NULL;

VMINT vm_sso_get_providers(vm_sso_provider_struct * buffer, VMUINT8 buffer_items)
{
    if (NULL == _vm_sso_get_providers)
        _vm_sso_get_providers = (_vm_sso_get_providers_t)vm_get_sym_entry("vm_sso_get_providers");

    if (NULL != _vm_sso_get_providers)
        return _vm_sso_get_providers(buffer,buffer_items);

    return (VMINT)-1;
}