#include "vmsys.h"
#include "vmssl.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ssl_get_verify_result_t)(VMINT handle);
_vm_ssl_get_verify_result_t _vm_ssl_get_verify_result = NULL;

VMINT vm_ssl_get_verify_result(VMINT handle)
{
    if (NULL == _vm_ssl_get_verify_result)
        _vm_ssl_get_verify_result = (_vm_ssl_get_verify_result_t)vm_get_sym_entry("vm_ssl_get_verify_result");
    if (NULL != _vm_ssl_get_verify_result)
        return _vm_ssl_get_verify_result(handle);
    return (VMINT)-1;
}