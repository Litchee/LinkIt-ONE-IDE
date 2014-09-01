#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ucs2_to_gb2312_t)(VMSTR dst, VMINT size, VMWSTR src);
_vm_ucs2_to_gb2312_t _vm_ucs2_to_gb2312 = NULL;

VMINT vm_ucs2_to_gb2312(VMSTR dst, VMINT size, VMWSTR src)
{
    if (NULL == _vm_ucs2_to_gb2312)
        _vm_ucs2_to_gb2312 = (_vm_ucs2_to_gb2312_t)vm_get_sym_entry("vm_ucs2_to_gb2312");

    if (NULL != _vm_ucs2_to_gb2312)
        return _vm_ucs2_to_gb2312(dst,size,src);

    return (VMINT )-1;
}
