#include "vmsys.h"
#include "vmrtspd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_rtspd_error_enum (*_vm_inet_rtspd_start_t)(VMUINT32 port, VMCHAR* root_dir);
_vm_inet_rtspd_start_t _vm_inet_rtspd_start = NULL;

vm_rtspd_error_enum vm_inet_rtspd_start(VMUINT32 port, VMCHAR* root_dir)
{
    if (NULL == _vm_inet_rtspd_start)
        _vm_inet_rtspd_start = (_vm_inet_rtspd_start_t)vm_get_sym_entry("vm_inet_rtspd_start");

    if (NULL != _vm_inet_rtspd_start)
        return _vm_inet_rtspd_start(port,root_dir);
        
    return (vm_rtspd_error_enum)-1;
}
