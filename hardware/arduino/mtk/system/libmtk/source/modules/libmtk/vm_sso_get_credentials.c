#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_credentials_t)(VMUINT32 provider, VMUINT8 account, vm_sso_credential_struct * buffer);
_vm_sso_get_credentials_t _vm_sso_get_credentials = NULL;

VMINT vm_sso_get_credentials(VMUINT32 provider, VMUINT8 account, vm_sso_credential_struct * buffer)
{
    if (NULL == _vm_sso_get_credentials)
        _vm_sso_get_credentials = (_vm_sso_get_credentials_t)vm_get_sym_entry("vm_sso_get_credentials");

    if (NULL != _vm_sso_get_credentials)
        return _vm_sso_get_credentials(provider,account,buffer);

    return (VMINT)-1;
}