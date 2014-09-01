#include "vmsys.h"
#include "vmhttp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_http_reg_receiver_t)(VMINT handle, http_data_receiver reciever);
_vm_http_reg_receiver_t _vm_http_reg_receiver = NULL;

VMINT vm_http_reg_receiver(VMINT handle, http_data_receiver reciever)
{
    if (NULL == _vm_http_reg_receiver)
        _vm_http_reg_receiver = (_vm_http_reg_receiver_t)vm_get_sym_entry("vm_http_reg_receiver");

    if (NULL != _vm_http_reg_receiver)
        return _vm_http_reg_receiver(handle,reciever);

    return (VMINT )-1;
}
