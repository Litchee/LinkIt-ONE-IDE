#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ascii_to_ucs2_t)(VMWSTR dst, VMINT size, VMSTR src);
_vm_ascii_to_ucs2_t _vm_ascii_to_ucs2 = NULL;

VMINT vm_ascii_to_ucs2(VMWSTR dst, VMINT size, VMSTR src)
{
    if (NULL == _vm_ascii_to_ucs2)
        _vm_ascii_to_ucs2 = (_vm_ascii_to_ucs2_t)vm_get_sym_entry("vm_ascii_to_ucs2");

    if (NULL != _vm_ascii_to_ucs2)
        return _vm_ascii_to_ucs2(dst,size,src);

    return (VMINT )-1;
}
