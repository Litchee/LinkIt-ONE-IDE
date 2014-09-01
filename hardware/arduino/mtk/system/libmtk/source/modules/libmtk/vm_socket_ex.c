#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_socket_ex_t)(int family, int type, int protocol, VMUINT32 data_account);
_vm_socket_ex_t _vm_socket_ex = NULL;

int vm_socket_ex(int family, int type, int protocol, VMUINT32 data_account)
{
    if (NULL == _vm_socket_ex)
        _vm_socket_ex = (_vm_socket_ex_t)vm_get_sym_entry("vm_socket_ex");
    if (NULL != _vm_socket_ex)
        return _vm_socket_ex(family,type,protocol,data_account);
    return (int)-100;
}