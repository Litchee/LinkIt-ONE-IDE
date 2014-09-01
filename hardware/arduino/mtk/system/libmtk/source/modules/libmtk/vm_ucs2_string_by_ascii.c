#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMWSTR (*_vm_ucs2_string_by_ascii_t)(VMSTR s);
_vm_ucs2_string_by_ascii_t _vm_ucs2_string_by_ascii = NULL;

VMWSTR vm_ucs2_string_by_ascii(VMSTR s)
{
    if (NULL == _vm_ucs2_string_by_ascii)
        _vm_ucs2_string_by_ascii = (_vm_ucs2_string_by_ascii_t)vm_get_sym_entry("vm_ucs2_string_by_ascii");

    if (NULL != _vm_ucs2_string_by_ascii)
        return _vm_ucs2_string_by_ascii(s);

    return (VMWSTR )NULL;
}
