#include "vmsys.h"
#include "vmftpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_ftpsrv_error_enum (*_vm_inet_ftpd_start_t)(VMUINT32 port, VMCHAR* root_dir);
_vm_inet_ftpd_start_t _vm_inet_ftpd_start = NULL;

vm_ftpsrv_error_enum vm_inet_ftpd_start(VMUINT32 port, VMCHAR* root_dir)
{
    if (NULL == _vm_inet_ftpd_start)
        _vm_inet_ftpd_start = (_vm_inet_ftpd_start_t)vm_get_sym_entry("vm_inet_ftpd_start");

    if (NULL != _vm_inet_ftpd_start)
        return _vm_inet_ftpd_start(port, root_dir);
        
    return (vm_ftpsrv_error_enum)-1;
}
