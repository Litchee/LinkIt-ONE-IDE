#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_http_free_handle_t)(VMINT handle);
_vm_http_free_handle_t _vm_http_free_handle = NULL;

void vm_http_free_handle(VMINT handle)
{
    if (NULL == _vm_http_free_handle)
        _vm_http_free_handle = (_vm_http_free_handle_t)vm_get_sym_entry("vm_http_free_handle");

    if (NULL != _vm_http_free_handle)
        _vm_http_free_handle(handle);

    
}
