#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_select_t)(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const timeval *timeout);
_vm_select_t _vm_select = NULL;

int vm_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const timeval *timeout)
{
    if (NULL == _vm_select)
        _vm_select = (_vm_select_t)vm_get_sym_entry("vm_select");
    if (NULL != _vm_select)
        return _vm_select(nfds,readfds,writefds,exceptfds,timeout);
    return (int)-100;
}