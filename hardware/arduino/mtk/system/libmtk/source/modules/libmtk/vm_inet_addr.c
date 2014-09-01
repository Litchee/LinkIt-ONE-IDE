#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT (*_vm_inet_addr_t)(const char* addr);
_vm_inet_addr_t _vm_inet_addr = NULL;

VMUINT vm_inet_addr(const char* addr)
{
    if (NULL == _vm_inet_addr)
        _vm_inet_addr = (_vm_inet_addr_t)vm_get_sym_entry("vm_inet_addr");
    if (NULL != _vm_inet_addr)
        return _vm_inet_addr(addr);
    return (VMUINT)0;
}