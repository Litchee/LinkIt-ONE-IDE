#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_tcp_close_t)(VMINT handle);
_vm_tcp_close_t _vm_tcp_close = NULL;

void vm_tcp_close(VMINT handle)
{
    if (NULL == _vm_tcp_close)
        _vm_tcp_close = (_vm_tcp_close_t)vm_get_sym_entry("vm_tcp_close");

    if (NULL != _vm_tcp_close)
        _vm_tcp_close(handle);

    
}
