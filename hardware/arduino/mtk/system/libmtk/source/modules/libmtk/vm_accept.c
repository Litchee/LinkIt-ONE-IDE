#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_accept_t)(int sock, SOCKADDR *addr, int *addrlen);
_vm_accept_t _vm_accept = NULL;

int vm_accept(int sock, SOCKADDR *addr, int *addrlen)
{
    if (NULL == _vm_accept)
        _vm_accept = (_vm_accept_t)vm_get_sym_entry("vm_accept");
    if (NULL != _vm_accept)
        return _vm_accept(sock,addr,addrlen);
    return (int)-100;
}