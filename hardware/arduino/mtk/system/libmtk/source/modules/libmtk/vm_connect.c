#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_connect_t)(int sock, SOCKADDR *addr, int addrlen);
_vm_connect_t _vm_connect = NULL;

int vm_connect(int sock, SOCKADDR *addr, int addrlen)
{
    if (NULL == _vm_connect)
        _vm_connect = (_vm_connect_t)vm_get_sym_entry("vm_connect");
    if (NULL != _vm_connect)
        return _vm_connect(sock,addr,addrlen);
    return (int)-100;
}