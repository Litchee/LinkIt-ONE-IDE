#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_recvfrom_t)(int sock, char *buf, int len, int flags, SOCKADDR *from, int *fromlen);
_vm_recvfrom_t _vm_recvfrom = NULL;

int vm_recvfrom(int sock, char *buf, int len, int flags, SOCKADDR *from, int *fromlen)
{
    if (NULL == _vm_recvfrom)
        _vm_recvfrom = (_vm_recvfrom_t)vm_get_sym_entry("vm_recvfrom");
    if (NULL != _vm_recvfrom)
        return _vm_recvfrom(sock,buf,len,flags,from,fromlen);
    return (int)-100;
}