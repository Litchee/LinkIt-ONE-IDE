#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_sendto_t)(int sock, const char *buf, int len, int flags, const SOCKADDR *to, int tolen);
_vm_sendto_t _vm_sendto = NULL;

int vm_sendto(int sock, const char *buf, int len, int flags, const SOCKADDR *to, int tolen)
{
    if (NULL == _vm_sendto)
        _vm_sendto = (_vm_sendto_t)vm_get_sym_entry("vm_sendto");
    if (NULL != _vm_sendto)
        return _vm_sendto(sock,buf,len,flags,to,tolen);
    return (int)-100;
}