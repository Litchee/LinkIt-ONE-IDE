#include "vmsys.h"
#include "vmrtspd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_rtspd_error_enum (*_vm_inet_rtspd_restart_t)(VMUINT32 port, VMCHAR* root_dir);
_vm_inet_rtspd_restart_t _vm_inet_rtspd_restart = NULL;

vm_rtspd_error_enum vm_inet_rtspd_restart(VMUINT32 port, VMCHAR* root_dir)
{
    if (NULL == _vm_inet_rtspd_restart)
        _vm_inet_rtspd_restart = (_vm_inet_rtspd_restart_t)vm_get_sym_entry("vm_inet_rtspd_restart");

    if (NULL != _vm_inet_rtspd_restart)
        return _vm_inet_rtspd_restart(port,root_dir);
        
    return (vm_rtspd_error_enum)-1;
}
