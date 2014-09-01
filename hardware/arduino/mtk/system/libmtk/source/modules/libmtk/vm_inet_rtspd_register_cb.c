#include "vmsys.h"
#include "vmrtspd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_rtspd_error_enum (*_vm_inet_rtspd_register_cb_t)(VM_RTSPD_CB callback);
_vm_inet_rtspd_register_cb_t _vm_inet_rtspd_register_cb = NULL;

vm_rtspd_error_enum vm_inet_rtspd_register_cb(VM_RTSPD_CB callback)
{
    if (NULL == _vm_inet_rtspd_register_cb)
        _vm_inet_rtspd_register_cb = (_vm_inet_rtspd_register_cb_t)vm_get_sym_entry("vm_inet_rtspd_register_cb");

    if (NULL != _vm_inet_rtspd_register_cb)
        return _vm_inet_rtspd_register_cb(callback);
        
    return (vm_rtspd_error_enum)-1;
}
