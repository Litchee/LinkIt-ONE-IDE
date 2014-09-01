#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_inet_httpd_enable_ssl_t)(VMUINT32 port, VMINT8* cer_dir, VMINT8* peer_cn, VMINT8* server_key_passwd);
_vm_inet_httpd_enable_ssl_t _vm_inet_httpd_enable_ssl = NULL;

void vm_inet_httpd_enable_ssl(VMUINT32 port, VMINT8* cer_dir, VMINT8* peer_cn, VMINT8* server_key_passwd)
{
    if (NULL == _vm_inet_httpd_enable_ssl)
        _vm_inet_httpd_enable_ssl = (_vm_inet_httpd_enable_ssl_t)vm_get_sym_entry("vm_inet_httpd_enable_ssl");

    if (NULL != _vm_inet_httpd_enable_ssl)
        _vm_inet_httpd_enable_ssl(port,cer_dir,peer_cn,server_key_passwd);
        
}
