#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_provider_icon_t)(VMUINT32 provider, vm_sso_icon_enum type, VMWCHAR ** icon_path);
_vm_sso_get_provider_icon_t _vm_sso_get_provider_icon = NULL;

VMINT vm_sso_get_provider_icon(VMUINT32 provider, vm_sso_icon_enum type, VMWCHAR ** icon_path)
{
    if (NULL == _vm_sso_get_provider_icon)
        _vm_sso_get_provider_icon = (_vm_sso_get_provider_icon_t)vm_get_sym_entry("vm_sso_get_provider_icon");

    if (NULL != _vm_sso_get_provider_icon)
        return _vm_sso_get_provider_icon(provider,type,icon_path);

    return (VMINT)-1;
}