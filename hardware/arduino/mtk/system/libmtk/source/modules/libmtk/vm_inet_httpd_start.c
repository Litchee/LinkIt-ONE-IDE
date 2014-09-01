#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_httpsrv_error_enum (*_vm_inet_httpd_start_t)(VMUINT32 port, VMINT8* root_dir, VMINT8* cgi_pattern);
_vm_inet_httpd_start_t _vm_inet_httpd_start = NULL;

vm_httpsrv_error_enum vm_inet_httpd_start(VMUINT32 port, VMINT8* root_dir, VMINT8* cgi_pattern)
{
    if (NULL == _vm_inet_httpd_start)
        _vm_inet_httpd_start = (_vm_inet_httpd_start_t)vm_get_sym_entry("vm_inet_httpd_start");

    if (NULL != _vm_inet_httpd_start)
        return _vm_inet_httpd_start(port, root_dir, cgi_pattern);
        
    return (vm_httpsrv_error_enum )-1;
}
