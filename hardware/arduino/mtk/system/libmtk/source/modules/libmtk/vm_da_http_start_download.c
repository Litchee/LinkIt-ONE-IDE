#include "vmsys.h"
#include "vmda.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_da_http_start_download_t)(vm_srv_da_start_download_struct * arg);
_vm_da_http_start_download_t _vm_da_http_start_download = NULL;

VMINT vm_da_http_start_download(vm_srv_da_start_download_struct * arg)
{
    if (NULL == _vm_da_http_start_download)
        _vm_da_http_start_download = (_vm_da_http_start_download_t)vm_get_sym_entry("vm_da_http_start_download");

    if (NULL != _vm_da_http_start_download)
        return _vm_da_http_start_download(arg);

    return (VMINT)-1;
}
