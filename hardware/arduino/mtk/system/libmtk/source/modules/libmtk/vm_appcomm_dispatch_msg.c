#include "vmsys.h"
#include "vmappcomm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_appcomm_dispatch_msg_t)(void);
_vm_appcomm_dispatch_msg_t _vm_appcomm_dispatch_msg = NULL;

void vm_appcomm_dispatch_msg(void)
{
    if (NULL == _vm_appcomm_dispatch_msg)
        _vm_appcomm_dispatch_msg = (_vm_appcomm_dispatch_msg_t)vm_get_sym_entry("vm_appcomm_dispatch_msg");

    if (NULL != _vm_appcomm_dispatch_msg)
        _vm_appcomm_dispatch_msg();

    
}
