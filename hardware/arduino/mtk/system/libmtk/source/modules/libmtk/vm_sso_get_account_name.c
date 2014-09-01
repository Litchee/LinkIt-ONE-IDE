#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_account_name_t)(VMUINT32 provider, VMUINT8 account, VMWCHAR * buffer);
_vm_sso_get_account_name_t _vm_sso_get_account_name = NULL;

VMINT vm_sso_get_account_name(VMUINT32 provider, VMUINT8 account, VMWCHAR * buffer)
{
    if (NULL == _vm_sso_get_account_name)
        _vm_sso_get_account_name = (_vm_sso_get_account_name_t)vm_get_sym_entry("vm_sso_get_account_name");

    if (NULL != _vm_sso_get_account_name)
        return _vm_sso_get_account_name(provider,account,buffer);

    return (VMINT)-1;
}