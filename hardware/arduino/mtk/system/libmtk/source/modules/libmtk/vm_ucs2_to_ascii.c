#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ucs2_to_ascii_t)(VMSTR dst, VMINT size, VMWSTR src);
_vm_ucs2_to_ascii_t _vm_ucs2_to_ascii = NULL;

VMINT vm_ucs2_to_ascii(VMSTR dst, VMINT size, VMWSTR src)
{
    if (NULL == _vm_ucs2_to_ascii)
        _vm_ucs2_to_ascii = (_vm_ucs2_to_ascii_t)vm_get_sym_entry("vm_ucs2_to_ascii");

    if (NULL != _vm_ucs2_to_ascii)
        return _vm_ucs2_to_ascii(dst,size,src);

    return (VMINT )-1;
}
