#include "vmsys.h"
#include "vmftpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_ftpsrv_error_enum (*_vm_inet_ftpd_stop_t)(void);
_vm_inet_ftpd_stop_t _vm_inet_ftpd_stop = NULL;

vm_ftpsrv_error_enum vm_inet_ftpd_stop(void)
{
    if (NULL == _vm_inet_ftpd_stop)
        _vm_inet_ftpd_stop = (_vm_inet_ftpd_stop_t)vm_get_sym_entry("vm_inet_ftpd_stop");

    if (NULL != _vm_inet_ftpd_stop)
        return _vm_inet_ftpd_stop();
        
    return (vm_ftpsrv_error_enum)-1;
}
