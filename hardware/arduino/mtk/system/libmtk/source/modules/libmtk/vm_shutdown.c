#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_shutdown_t)(int sock, int how);
_vm_shutdown_t _vm_shutdown = NULL;

int vm_shutdown(int sock, int how)
{
    if (NULL == _vm_shutdown)
        _vm_shutdown = (_vm_shutdown_t)vm_get_sym_entry("vm_shutdown");
    if (NULL != _vm_shutdown)
        return _vm_shutdown(sock,how);
    return (int)-100;
}