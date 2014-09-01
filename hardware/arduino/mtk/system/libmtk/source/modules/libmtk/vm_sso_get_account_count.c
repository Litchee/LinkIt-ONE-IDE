#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_account_count_t)(VMUINT32 provider, vm_sso_login_state login_state);
_vm_sso_get_account_count_t _vm_sso_get_account_count = NULL;

VMINT vm_sso_get_account_count(VMUINT32 provider, vm_sso_login_state login_state)
{
    if (NULL == _vm_sso_get_account_count)
        _vm_sso_get_account_count = (_vm_sso_get_account_count_t)vm_get_sym_entry("vm_sso_get_account_count");

    if (NULL != _vm_sso_get_account_count)
        return _vm_sso_get_account_count(provider,login_state);

    return (VMINT)-1;
}