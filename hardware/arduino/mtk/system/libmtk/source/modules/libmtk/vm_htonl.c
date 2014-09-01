#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT32 (*_vm_htonl_t)(VMUINT32 a);
_vm_htonl_t _vm_htonl = NULL;

VMUINT32 vm_htonl(VMUINT32 a)
{
    if (NULL == _vm_htonl)
        _vm_htonl = (_vm_htonl_t)vm_get_sym_entry("vm_htonl");
    if (NULL != _vm_htonl)
        return _vm_htonl(a);
    return (VMUINT32)-100;
}