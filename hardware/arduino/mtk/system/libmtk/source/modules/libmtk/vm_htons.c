#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT16 (*_vm_htons_t)(VMUINT16 a);
_vm_htons_t _vm_htons = NULL;

VMUINT16 vm_htons(VMUINT16 a)
{
    if (NULL == _vm_htons)
        _vm_htons = (_vm_htons_t)vm_get_sym_entry("vm_htons");
    if (NULL != _vm_htons)
        return _vm_htons(a);
    return (VMUINT16)-100;
}