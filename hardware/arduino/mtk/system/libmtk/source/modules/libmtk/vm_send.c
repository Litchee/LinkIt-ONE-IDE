#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_send_t)(int sock, const char *buf, int len, int flags);
_vm_send_t _vm_send = NULL;

int vm_send(int sock, const char *buf, int len, int flags)
{
    if (NULL == _vm_send)
        _vm_send = (_vm_send_t)vm_get_sym_entry("vm_send");
    if (NULL != _vm_send)
        return _vm_send(sock,buf,len,flags);
    return (int)-100;
}