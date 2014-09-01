#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_getsockopt_t)(int sock, VMUINT32 option, void *val, VMUINT8 val_size);
_vm_getsockopt_t _vm_getsockopt = NULL;

int vm_getsockopt(int sock, VMUINT32 option, void *val, VMUINT8 val_size)
{
    if (NULL == _vm_getsockopt)
        _vm_getsockopt = (_vm_getsockopt_t)vm_get_sym_entry("vm_getsockopt");
    if (NULL != _vm_getsockopt)
        return _vm_getsockopt(sock,option,val,val_size);
    return (int)-100;
}