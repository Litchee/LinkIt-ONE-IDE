#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_refresh_credentials_t)(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data);
_vm_sso_refresh_credentials_t _vm_sso_refresh_credentials = NULL;

VMINT vm_sso_refresh_credentials(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data)
{
    if (NULL == _vm_sso_refresh_credentials)
        _vm_sso_refresh_credentials = (_vm_sso_refresh_credentials_t)vm_get_sym_entry("vm_sso_refresh_credentials");

    if (NULL != _vm_sso_refresh_credentials)
        return _vm_sso_refresh_credentials(provider,account,callback,user_data);

    return (VMINT)-1;
}