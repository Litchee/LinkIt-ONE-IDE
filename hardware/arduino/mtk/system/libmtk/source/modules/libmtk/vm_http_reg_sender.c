#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_reg_sender_t)(VMINT handle, http_data_sender sender);
_vm_http_reg_sender_t _vm_http_reg_sender = NULL;

VMINT vm_http_reg_sender(VMINT handle, http_data_sender sender)
{
    if (NULL == _vm_http_reg_sender)
        _vm_http_reg_sender = (_vm_http_reg_sender_t)vm_get_sym_entry("vm_http_reg_sender");

    if (NULL != _vm_http_reg_sender)
        return _vm_http_reg_sender(handle,sender);

    return (VMINT )-1;
}
