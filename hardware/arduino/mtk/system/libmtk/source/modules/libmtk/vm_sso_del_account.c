#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_del_account_t)(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data);
_vm_sso_del_account_t _vm_sso_del_account = NULL;

VMINT vm_sso_del_account(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data)
{
    if (NULL == _vm_sso_del_account)
        _vm_sso_del_account = (_vm_sso_del_account_t)vm_get_sym_entry("vm_sso_del_account");

    if (NULL != _vm_sso_del_account)
        return _vm_sso_del_account(provider,account,callback,user_data);

    return (VMINT)-1;
}