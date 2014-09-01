#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_bind_t)(int sock, const SOCKADDR *addr, int addrlen, int type);
_vm_bind_t _vm_bind = NULL;

int vm_bind(int sock, const SOCKADDR *addr, int addrlen, int type)
{
    if (NULL == _vm_bind)
        _vm_bind = (_vm_bind_t)vm_get_sym_entry("vm_bind");
    if (NULL != _vm_bind)
        return _vm_bind(sock,addr,addrlen,type);
    return (int)-100;
}