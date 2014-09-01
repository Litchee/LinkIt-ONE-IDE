#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_inet_httpd_disable_ssl_t)();
_vm_inet_httpd_disable_ssl_t _vm_inet_httpd_disable_ssl = NULL;

void vm_inet_httpd_disable_ssl()
{
    if (NULL == _vm_inet_httpd_disable_ssl)
        _vm_inet_httpd_disable_ssl = (_vm_inet_httpd_disable_ssl_t)vm_get_sym_entry("vm_inet_httpd_disable_ssl");

    if (NULL != _vm_inet_httpd_disable_ssl)
        _vm_inet_httpd_disable_ssl();
        
}
