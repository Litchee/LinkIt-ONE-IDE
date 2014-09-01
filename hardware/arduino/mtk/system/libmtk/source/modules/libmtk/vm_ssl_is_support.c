#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_is_support_t)(void);
_vm_ssl_is_support_t _vm_ssl_is_support = NULL;

VMINT vm_ssl_is_support(void)
{
    if (NULL == _vm_ssl_is_support)
        _vm_ssl_is_support = (_vm_ssl_is_support_t)vm_get_sym_entry("vm_ssl_is_support");
    if (NULL != _vm_ssl_is_support)
        return _vm_ssl_is_support();
    return (VMINT)0;
}