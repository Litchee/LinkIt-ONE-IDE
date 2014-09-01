#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_add_account_t)(VMUINT32 provider, const VMWCHAR * username, const VMWCHAR * password, vm_sso_account_callback callback, void * user_data);
_vm_sso_add_account_t _vm_sso_add_account = NULL;

VMINT vm_sso_add_account(VMUINT32 provider, const VMWCHAR * username, const VMWCHAR * password, vm_sso_account_callback callback, void * user_data)
{
    if (NULL == _vm_sso_add_account)
        _vm_sso_add_account = (_vm_sso_add_account_t)vm_get_sym_entry("vm_sso_add_account");

    if (NULL != _vm_sso_add_account)
        return _vm_sso_add_account(provider,username,password,callback,user_data);

    return (VMINT)-1;
}