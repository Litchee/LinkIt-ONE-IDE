#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_socket_t)(int family, int type, int protocol);
_vm_socket_t _vm_socket = NULL;

int vm_socket(int family, int type, int protocol)
{
    if (NULL == _vm_socket)
        _vm_socket = (_vm_socket_t)vm_get_sym_entry("vm_socket");
    if (NULL != _vm_socket)
        return _vm_socket(family,type,protocol);
    return (int)-100;
}