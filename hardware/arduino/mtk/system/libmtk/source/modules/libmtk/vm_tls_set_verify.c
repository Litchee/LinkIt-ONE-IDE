#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_set_verify_t)(VMINT res_id, VMUINT32 cert_id[], VMINT cert_num, vm_tls_filetype_enum type);
_vm_tls_set_verify_t _vm_tls_set_verify = NULL;

VMINT vm_tls_set_verify(VMINT res_id, VMUINT32 cert_id[], VMINT cert_num, vm_tls_filetype_enum type)
{
    if (NULL == _vm_tls_set_verify)
        _vm_tls_set_verify = (_vm_tls_set_verify_t)vm_get_sym_entry("vm_tls_set_verify");

    if (NULL != _vm_tls_set_verify)
        return _vm_tls_set_verify(res_id,cert_id,cert_num,type);

    return (VMINT)-1;
}