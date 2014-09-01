#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_preview_t)(vm_vdorec_preview_struct* para);
_vm_vdorec_preview_t _vm_vdorec_preview = NULL;

VMINT vm_vdorec_preview(vm_vdorec_preview_struct* para)
{
    if (NULL == _vm_vdorec_preview)
        _vm_vdorec_preview = (_vm_vdorec_preview_t)vm_get_sym_entry("vm_vdorec_preview");

    if (NULL != _vm_vdorec_preview)
        return _vm_vdorec_preview(para);

    return (VMINT )-1;
}
