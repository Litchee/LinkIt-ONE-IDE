#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_get_current_handle_t)(void);
_vm_http_get_current_handle_t _vm_http_get_current_handle = NULL;

VMINT vm_http_get_current_handle(void)
{
    if (NULL == _vm_http_get_current_handle)
        _vm_http_get_current_handle = (_vm_http_get_current_handle_t)vm_get_sym_entry("vm_http_get_current_handle");

    if (NULL != _vm_http_get_current_handle)
        return _vm_http_get_current_handle();

    return (VMINT )-1;
}
