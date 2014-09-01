#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT16 (*_vm_sms_get_msg_id_t)(vm_sms_box_enum box_type, VMUINT16 msg_index);
_vm_sms_get_msg_id_t _vm_sms_get_msg_id = NULL;

VMINT16 vm_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index)
{
    if (NULL == _vm_sms_get_msg_id)
        _vm_sms_get_msg_id = (_vm_sms_get_msg_id_t)vm_get_sym_entry("vm_sms_get_msg_id");

    if (NULL != _vm_sms_get_msg_id)
        return _vm_sms_get_msg_id(box_type,msg_index);

    return (VMINT16 )-1;
}
