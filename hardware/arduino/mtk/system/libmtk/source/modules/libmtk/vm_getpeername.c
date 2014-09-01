#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_getpeername_t)(int s, SOCKADDR *addr, int *len);
_vm_getpeername_t _vm_getpeername = NULL;

int vm_getpeername(int s, SOCKADDR *addr, int *len)
{
    if (NULL == _vm_getpeername)
        _vm_getpeername = (_vm_getpeername_t)vm_get_sym_entry("vm_getpeername");
    if (NULL != _vm_getpeername)
        return _vm_getpeername(s,addr,len);
    return (int)-100;
}