#include "vmsys.h"
#include "vmtls.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tls_read_t)(VMINT res_id, void* buf, VMINT32 len);
_vm_tls_read_t _vm_tls_read = NULL;

VMINT vm_tls_read(VMINT res_id, void* buf, VMINT32 len)
{
    if (NULL == _vm_tls_read)
        _vm_tls_read = (_vm_tls_read_t)vm_get_sym_entry("vm_tls_read");

    if (NULL != _vm_tls_read)
        return _vm_tls_read(res_id,buf,len);

    return (VMINT)-1;
}