#include "vmsys.h"
#include "vmcert.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ce_auth_app_ex_t)(VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, VMINT mode );
_vm_ce_auth_app_ex_t _vm_ce_auth_app_ex = NULL;

VMINT vm_ce_auth_app_ex( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, VMINT mode )
{
    if (NULL == _vm_ce_auth_app_ex)
        _vm_ce_auth_app_ex = (_vm_ce_auth_app_ex_t)vm_get_sym_entry("vm_ce_auth_app_ex");

    if (NULL != _vm_ce_auth_app_ex)
        return _vm_ce_auth_app_ex(filename,cache_buf,cache_len, mode);

    return (VMINT )-1;
}
