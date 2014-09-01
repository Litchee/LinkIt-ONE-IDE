#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT16 (*_vm_sms_get_box_size_t)(vm_sms_box_enum box_type);
_vm_sms_get_box_size_t _vm_sms_get_box_size = NULL;

VMINT16 vm_sms_get_box_size(vm_sms_box_enum box_type)
{
    if (NULL == _vm_sms_get_box_size)
        _vm_sms_get_box_size = (_vm_sms_get_box_size_t)vm_get_sym_entry("vm_sms_get_box_size");

    if (NULL != _vm_sms_get_box_size)
        return _vm_sms_get_box_size(box_type);

    return (VMINT16 )-1;
}
