#include "vmsys.h"
#include "vmsms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_sms_is_sms_ready_t)(void);
_vm_sms_is_sms_ready_t _vm_sms_is_sms_ready = NULL;

VMBOOL vm_sms_is_sms_ready(void)
{
    if (NULL == _vm_sms_is_sms_ready)
        _vm_sms_is_sms_ready = (_vm_sms_is_sms_ready_t)vm_get_sym_entry("vm_sms_is_sms_ready");
    if (NULL != _vm_sms_is_sms_ready)
        return _vm_sms_is_sms_ready();
    return (VMBOOL)-1;
}