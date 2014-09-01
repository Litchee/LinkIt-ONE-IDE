#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_closesocket_t)(int sock);
_vm_closesocket_t _vm_closesocket = NULL;

int vm_closesocket(int sock)
{
    if (NULL == _vm_closesocket)
        _vm_closesocket = (_vm_closesocket_t)vm_get_sym_entry("vm_closesocket");
    if (NULL != _vm_closesocket)
        return _vm_closesocket(sock);
    return (int)-100;
}