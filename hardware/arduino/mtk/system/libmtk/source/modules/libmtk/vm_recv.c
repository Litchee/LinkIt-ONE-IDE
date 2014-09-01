#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_recv_t)(int sock, char *buf, int len, int flags);
_vm_recv_t _vm_recv = NULL;

int vm_recv(int sock, char *buf, int len, int flags)
{
    if (NULL == _vm_recv)
        _vm_recv = (_vm_recv_t)vm_get_sym_entry("vm_recv");
    if (NULL != _vm_recv)
        return _vm_recv(sock,buf,len,flags);
    return (int)-100;
}