#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_write_t)(VMINT res_id, const void* buf, VMINT32 len);
_vm_tls_write_t _vm_tls_write = NULL;

VMINT vm_tls_write(VMINT res_id, const void* buf, VMINT32 len)
{
    if (NULL == _vm_tls_write)
        _vm_tls_write = (_vm_tls_write_t)vm_get_sym_entry("vm_tls_write");

    if (NULL != _vm_tls_write)
        return _vm_tls_write(res_id,buf,len);

    return (VMINT)-1;
}