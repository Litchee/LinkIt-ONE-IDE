#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_get_account_t)(VMUINT32 provider, VMUINT8 account, vm_sso_account_struct * buffer);
_vm_sso_get_account_t _vm_sso_get_account = NULL;

VMINT vm_sso_get_account(VMUINT32 provider, VMUINT8 account, vm_sso_account_struct * buffer)
{
    if (NULL == _vm_sso_get_account)
        _vm_sso_get_account = (_vm_sso_get_account_t)vm_get_sym_entry("vm_sso_get_account");

    if (NULL != _vm_sso_get_account)
        return _vm_sso_get_account(provider,account,buffer);

    return (VMINT)-1;
}