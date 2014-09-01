#include "vmsys.h"
#include "vmmms.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_mms_cancel_send_mms_t)(void);
_vm_mms_cancel_send_mms_t _vm_mms_cancel_send_mms = NULL;

void vm_mms_cancel_send_mms(void)
{
    if (NULL == _vm_mms_cancel_send_mms)
        _vm_mms_cancel_send_mms = (_vm_mms_cancel_send_mms_t)vm_get_sym_entry("vm_mms_cancel_send_mms");

    if (NULL != _vm_mms_cancel_send_mms)
        _vm_mms_cancel_send_mms();

    
}
