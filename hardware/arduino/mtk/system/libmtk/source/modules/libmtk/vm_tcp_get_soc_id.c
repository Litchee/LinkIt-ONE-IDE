#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_tcp_get_soc_id_t)(VMINT hdl);
_vm_tcp_get_soc_id_t _vm_tcp_get_soc_id = NULL;

VMINT vm_tcp_get_soc_id(VMINT hdl)
{
    if (NULL == _vm_tcp_get_soc_id)
        _vm_tcp_get_soc_id = (_vm_tcp_get_soc_id_t)vm_get_sym_entry("vm_tcp_get_soc_id");
    if (NULL != _vm_tcp_get_soc_id)
        return _vm_tcp_get_soc_id(hdl);
    return (VMINT)-1;
}