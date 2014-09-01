#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_reg_http_notification_t)(void (*f)(VMINT state, VMINT param));
_vm_reg_http_notification_t _vm_reg_http_notification = NULL;

void vm_reg_http_notification(void (*f)(VMINT state, VMINT param))
{
    if (NULL == _vm_reg_http_notification)
        _vm_reg_http_notification = (_vm_reg_http_notification_t)vm_get_sym_entry("vm_reg_http_notification");

    if (NULL != _vm_reg_http_notification)
        _vm_reg_http_notification(f);

    
}
