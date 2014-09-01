#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_record_t)(vm_vdorec_record_struct* para);
_vm_vdorec_record_t _vm_vdorec_record = NULL;

VMINT vm_vdorec_record(vm_vdorec_record_struct* para)
{
    if (NULL == _vm_vdorec_record)
        _vm_vdorec_record = (_vm_vdorec_record_t)vm_get_sym_entry("vm_vdorec_record");

    if (NULL != _vm_vdorec_record)
        return _vm_vdorec_record(para);

    return (VMINT )-1;
}
