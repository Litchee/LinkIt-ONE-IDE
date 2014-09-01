#include "vmsys.h"
#include "vmpn.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_pn_query_t)(vm_srv_pns_query_event query_id, void * user_data);
_vm_pn_query_t _vm_pn_query = NULL;

VMINT vm_pn_query(vm_srv_pns_query_event query_id, void * user_data)
{
    if (NULL == _vm_pn_query)
        _vm_pn_query = (_vm_pn_query_t)vm_get_sym_entry("vm_pn_query");

    if (NULL != _vm_pn_query)
        return _vm_pn_query(query_id,user_data);

    return (VMINT)-1;
}