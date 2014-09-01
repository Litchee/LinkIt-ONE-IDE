#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_close_t)(VMINT handle);
_vm_ssl_close_t _vm_ssl_close = NULL;

VMINT vm_ssl_close(VMINT handle)
{
    if (NULL == _vm_ssl_close)
        _vm_ssl_close = (_vm_ssl_close_t)vm_get_sym_entry("vm_ssl_close");
    if (NULL != _vm_ssl_close)
        return _vm_ssl_close(handle);
    return (VMINT)-1;
}