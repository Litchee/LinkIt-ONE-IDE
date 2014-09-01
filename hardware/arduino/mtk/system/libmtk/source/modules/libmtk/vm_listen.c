#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_listen_t)(int sock, int backlog);
_vm_listen_t _vm_listen = NULL;

int vm_listen(int sock, int backlog)
{
    if (NULL == _vm_listen)
        _vm_listen = (_vm_listen_t)vm_get_sym_entry("vm_listen");
    if (NULL != _vm_listen)
        return _vm_listen(sock,backlog);
    return (int)-100;
}