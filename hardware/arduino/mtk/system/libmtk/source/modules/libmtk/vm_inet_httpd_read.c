#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT32 (*_vm_inet_httpd_read_t)(VMUINT32 hc_handle, VMINT8* buf, VMINT32 buf_size);
_vm_inet_httpd_read_t _vm_inet_httpd_read = NULL;

VMINT32 vm_inet_httpd_read(VMUINT32 hc_handle, VMINT8* buf, VMINT32 buf_size)
{
    if (NULL == _vm_inet_httpd_read)
        _vm_inet_httpd_read = (_vm_inet_httpd_read_t)vm_get_sym_entry("vm_inet_httpd_read");

    if (NULL != _vm_inet_httpd_read)
        return _vm_inet_httpd_read(hc_handle,buf,buf_size);
        
    return (VMINT32 )-1;
}
