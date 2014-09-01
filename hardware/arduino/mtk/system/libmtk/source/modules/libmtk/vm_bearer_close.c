#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_bearer_close_t)(VMINT hdl);
_vm_bearer_close_t _vm_bearer_close = NULL;

VMINT vm_bearer_close(VMINT hdl)
{
    if (NULL == _vm_bearer_close)
        _vm_bearer_close = (_vm_bearer_close_t)vm_get_sym_entry("vm_bearer_close");
    if (NULL != _vm_bearer_close)
        return _vm_bearer_close(hdl);
    return (VMINT)-100;
}