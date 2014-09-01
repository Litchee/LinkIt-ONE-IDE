#include "vmsys.h"
#include "vmda.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_da_http_dl_operation_t)(VMINT hdl, vm_srv_da_download_cause_enum cause);
_vm_da_http_dl_operation_t _vm_da_http_dl_operation = NULL;

VMINT vm_da_http_dl_operation(VMINT hdl, vm_srv_da_download_cause_enum cause)
{
    if (NULL == _vm_da_http_dl_operation)
        _vm_da_http_dl_operation = (_vm_da_http_dl_operation_t)vm_get_sym_entry("vm_da_http_dl_operation");

    if (NULL != _vm_da_http_dl_operation)
        return _vm_da_http_dl_operation(hdl,cause);

    return (VMINT)-1;
}