#include "vmsys.h"
#include "vmtel.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ivr_call_t)(vm_ivr_call_data* data);
_vm_ivr_call_t _vm_ivr_call = NULL;

VMINT vm_ivr_call(vm_ivr_call_data* data)
{
    if (NULL == _vm_ivr_call)
        _vm_ivr_call = (_vm_ivr_call_t)vm_get_sym_entry("vm_ivr_call");

    if (NULL != _vm_ivr_call)
        return _vm_ivr_call(data);

    return (VMINT )-1;
}
