#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef int (*_vm_setsockopt_t)(int sock, VMUINT32 option, void *val, VMUINT8 val_size);
_vm_setsockopt_t _vm_setsockopt = NULL;

int vm_setsockopt(int sock, VMUINT32 option, void *val, VMUINT8 val_size)
{
    if (NULL == _vm_setsockopt)
        _vm_setsockopt = (_vm_setsockopt_t)vm_get_sym_entry("vm_setsockopt");
    if (NULL != _vm_setsockopt)
        return _vm_setsockopt(sock,option,val,val_size);
    return (int)-100;
}