#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_set_current_handle_t)(VMINT handle);
_vm_http_set_current_handle_t _vm_http_set_current_handle = NULL;

VMINT vm_http_set_current_handle(VMINT handle)
{
    if (NULL == _vm_http_set_current_handle)
        _vm_http_set_current_handle = (_vm_http_set_current_handle_t)vm_get_sym_entry("vm_http_set_current_handle");

    if (NULL != _vm_http_set_current_handle)
        return _vm_http_set_current_handle(handle);

    return (VMINT )-1;
}
