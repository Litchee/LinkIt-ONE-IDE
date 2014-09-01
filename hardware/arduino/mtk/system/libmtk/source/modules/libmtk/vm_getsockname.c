#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_getsockname_t)(int s, SOCKADDR *addr, int *len);
_vm_getsockname_t _vm_getsockname = NULL;

int vm_getsockname(int s, SOCKADDR *addr, int *len)
{
    if (NULL == _vm_getsockname)
        _vm_getsockname = (_vm_getsockname_t)vm_get_sym_entry("vm_getsockname");
    if (NULL != _vm_getsockname)
        return _vm_getsockname(s,addr,len);
    return (int)-100;
}