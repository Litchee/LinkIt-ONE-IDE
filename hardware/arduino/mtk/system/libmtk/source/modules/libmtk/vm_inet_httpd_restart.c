#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_httpsrv_error_enum (*_vm_inet_httpd_restart_t)(VMUINT32 port, VMINT8* root_dir, VMINT8* cgi_pattern);
_vm_inet_httpd_restart_t _vm_inet_httpd_restart = NULL;

vm_httpsrv_error_enum vm_inet_httpd_restart(VMUINT32 port, VMINT8* root_dir, VMINT8* cgi_pattern)
{
    if (NULL == _vm_inet_httpd_restart)
        _vm_inet_httpd_restart = (_vm_inet_httpd_restart_t)vm_get_sym_entry("vm_inet_httpd_restart");

    if (NULL != _vm_inet_httpd_restart)
        return _vm_inet_httpd_restart(port,root_dir,cgi_pattern);
        
    return (vm_httpsrv_error_enum )-1;
}
