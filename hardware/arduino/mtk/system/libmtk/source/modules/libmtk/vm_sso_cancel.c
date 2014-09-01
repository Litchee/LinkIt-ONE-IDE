#include "vmsys.h"
#include "vmsso.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_sso_cancel_t)(VMINT req_id);
_vm_sso_cancel_t _vm_sso_cancel = NULL;

VMINT vm_sso_cancel(VMINT req_id)
{
    if (NULL == _vm_sso_cancel)
        _vm_sso_cancel = (_vm_sso_cancel_t)vm_get_sym_entry("vm_sso_cancel");

    if (NULL != _vm_sso_cancel)
        return _vm_sso_cancel(req_id);

    return (VMINT)-1;
}