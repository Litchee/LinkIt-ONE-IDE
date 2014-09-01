#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_bearer_open_t)(VMINT apn, void *user_data, void (*callback)(VMINT handle, VMINT event, VMUINT param, void *user_data));
_vm_bearer_open_t _vm_bearer_open = NULL;

VMINT vm_bearer_open(VMINT apn, void *user_data, void (*callback)(VMINT handle, VMINT event, VMUINT param, void *user_data))
{
    if (NULL == _vm_bearer_open)
        _vm_bearer_open = (_vm_bearer_open_t)vm_get_sym_entry("vm_bearer_open");
    if (NULL != _vm_bearer_open)
        return _vm_bearer_open(apn,user_data,callback);
    return (VMINT)-100;
}