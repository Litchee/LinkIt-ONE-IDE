#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_logout_account_t)(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data);
_vm_sso_logout_account_t _vm_sso_logout_account = NULL;

VMINT vm_sso_logout_account(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data)
{
    if (NULL == _vm_sso_logout_account)
        _vm_sso_logout_account = (_vm_sso_logout_account_t)vm_get_sym_entry("vm_sso_logout_account");

    if (NULL != _vm_sso_logout_account)
        return _vm_sso_logout_account(provider,account,callback,user_data);

    return (VMINT)-1;
}