#include "vmsys.h"
#include "vmhttpd.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_inet_httpd_cgi_job_finish_t)(VMUINT32 hc_handle);
_vm_inet_httpd_cgi_job_finish_t _vm_inet_httpd_cgi_job_finish = NULL;

void vm_inet_httpd_cgi_job_finish(VMUINT32 hc_handle)
{
    if (NULL == _vm_inet_httpd_cgi_job_finish)
        _vm_inet_httpd_cgi_job_finish = (_vm_inet_httpd_cgi_job_finish_t)vm_get_sym_entry("vm_inet_httpd_cgi_job_finish");

    if (NULL != _vm_inet_httpd_cgi_job_finish)
        _vm_inet_httpd_cgi_job_finish(hc_handle);
        
}
