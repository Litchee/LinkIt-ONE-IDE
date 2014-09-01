#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_inet_httpd_write_t)(VMUINT32 hc_handle, VMINT8* buf, VMINT32 content_size);
_vm_inet_httpd_write_t _vm_inet_httpd_write = NULL;

VMINT32 vm_inet_httpd_write(VMUINT32 hc_handle, VMINT8* buf, VMINT32 content_size)
{
    if (NULL == _vm_inet_httpd_write)
        _vm_inet_httpd_write = (_vm_inet_httpd_write_t)vm_get_sym_entry("vm_inet_httpd_write");

    if (NULL != _vm_inet_httpd_write)
        return _vm_inet_httpd_write(hc_handle,buf,content_size);
        
    return (VMINT32 )-1;
}
