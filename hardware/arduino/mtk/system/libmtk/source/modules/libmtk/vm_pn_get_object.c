#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_get_object_t)(const VMCHAR * msgBody, const VMCHAR * key, vm_srv_pns_msg_value_struct * value);
_vm_pn_get_object_t _vm_pn_get_object = NULL;

VMINT vm_pn_get_object(const VMCHAR * msgBody, const VMCHAR * key, vm_srv_pns_msg_value_struct * value)
{
    if (NULL == _vm_pn_get_object)
        _vm_pn_get_object = (_vm_pn_get_object_t)vm_get_sym_entry("vm_pn_get_object");

    if (NULL != _vm_pn_get_object)
        return _vm_pn_get_object(msgBody,key,value);

    return (VMINT)-1;
}