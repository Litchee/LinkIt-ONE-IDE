#include "vmsys.h"
#include "vmchset.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_chset_convert_t)(vm_chset_enum src_type, vm_chset_enum dest_type, VMCHAR *src, VMCHAR *dest, VMINT dest_size);
_vm_chset_convert_t _vm_chset_convert = NULL;

VMINT vm_chset_convert(vm_chset_enum src_type, vm_chset_enum dest_type, VMCHAR *src, VMCHAR *dest, VMINT dest_size)
{
    if (NULL == _vm_chset_convert)
        _vm_chset_convert = (_vm_chset_convert_t)vm_get_sym_entry("vm_chset_convert");

    if (NULL != _vm_chset_convert)
        return _vm_chset_convert(src_type,dest_type,src,dest,dest_size);

    return (VMINT )-1;
}
