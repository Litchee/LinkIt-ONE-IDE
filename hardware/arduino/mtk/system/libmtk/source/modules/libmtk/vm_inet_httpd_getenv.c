#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT8* (*_vm_inet_httpd_getenv_t)(VMUINT32 hc_handle, VMINT8* name);
_vm_inet_httpd_getenv_t _vm_inet_httpd_getenv = NULL;

VMINT8* vm_inet_httpd_getenv(VMUINT32 hc_handle, VMINT8* name)
{
    if (NULL == _vm_inet_httpd_getenv)
        _vm_inet_httpd_getenv = (_vm_inet_httpd_getenv_t)vm_get_sym_entry("vm_inet_httpd_getenv");

    if (NULL != _vm_inet_httpd_getenv)
        return _vm_inet_httpd_getenv(hc_handle,name);
        
    return (VMINT8* )-1;
}
