#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_accounts_t)(VMUINT32 provider, vm_sso_login_state login_state, vm_sso_account_struct * buffer, VMUINT8 buffer_items);
_vm_sso_get_accounts_t _vm_sso_get_accounts = NULL;

VMINT vm_sso_get_accounts(VMUINT32 provider, vm_sso_login_state login_state, vm_sso_account_struct * buffer, VMUINT8 buffer_items)
{
    if (NULL == _vm_sso_get_accounts)
        _vm_sso_get_accounts = (_vm_sso_get_accounts_t)vm_get_sym_entry("vm_sso_get_accounts");

    if (NULL != _vm_sso_get_accounts)
        return _vm_sso_get_accounts(provider,login_state,buffer,buffer_items);

    return (VMINT)-1;
}