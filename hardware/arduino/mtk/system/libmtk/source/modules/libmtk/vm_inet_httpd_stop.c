#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef vm_httpsrv_error_enum (*_vm_inet_httpd_stop_t)(void);
_vm_inet_httpd_stop_t _vm_inet_httpd_stop = NULL;

vm_httpsrv_error_enum vm_inet_httpd_stop(void)
{
    if (NULL == _vm_inet_httpd_stop)
        _vm_inet_httpd_stop = (_vm_inet_httpd_stop_t)vm_get_sym_entry("vm_inet_httpd_stop");

    if (NULL != _vm_inet_httpd_stop)
        return _vm_inet_httpd_stop();
        
    return (vm_httpsrv_error_enum )-1;
}
