#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_login_account_t)(VMUINT32 provider, VMUINT8 account, const VMWCHAR * password, vm_sso_account_callback callback, void * user_data);
_vm_sso_login_account_t _vm_sso_login_account = NULL;

VMINT vm_sso_login_account(VMUINT32 provider, VMUINT8 account, const VMWCHAR * password, vm_sso_account_callback callback, void * user_data)
{
    if (NULL == _vm_sso_login_account)
        _vm_sso_login_account = (_vm_sso_login_account_t)vm_get_sym_entry("vm_sso_login_account");

    if (NULL != _vm_sso_login_account)
        return _vm_sso_login_account(provider,account,password,callback,user_data);

    return (VMINT)-1;
}