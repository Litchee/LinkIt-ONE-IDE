#include "vmsys.h"
#include "vmrtspd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_rtspd_error_enum (*_vm_inet_rtspd_stop_t)(void);
_vm_inet_rtspd_stop_t _vm_inet_rtspd_stop = NULL;

vm_rtspd_error_enum vm_inet_rtspd_stop(void)
{
    if (NULL == _vm_inet_rtspd_stop)
        _vm_inet_rtspd_stop = (_vm_inet_rtspd_stop_t)vm_get_sym_entry("vm_inet_rtspd_stop");

    if (NULL != _vm_inet_rtspd_stop)
        return _vm_inet_rtspd_stop();
        
    return (vm_rtspd_error_enum)-1;
}
