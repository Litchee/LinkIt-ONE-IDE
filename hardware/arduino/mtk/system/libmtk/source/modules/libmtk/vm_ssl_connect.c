#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_connect_t)(const vm_ssl_cntx *ctx);
_vm_ssl_connect_t _vm_ssl_connect = NULL;

VMINT vm_ssl_connect(const vm_ssl_cntx *ctx)
{
    if (NULL == _vm_ssl_connect)
        _vm_ssl_connect = (_vm_ssl_connect_t)vm_get_sym_entry("vm_ssl_connect");
    if (NULL != _vm_ssl_connect)
        return _vm_ssl_connect(ctx);
    return (VMINT)-1;
}