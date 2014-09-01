#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_get_soc_id_t)(VMINT hdl);
_vm_soc_svr_get_soc_id_t _vm_soc_svr_get_soc_id = NULL;

VMINT vm_soc_svr_get_soc_id(VMINT hdl)
{
    if (NULL == _vm_soc_svr_get_soc_id)
        _vm_soc_svr_get_soc_id = (_vm_soc_svr_get_soc_id_t)vm_get_sym_entry("vm_soc_svr_get_soc_id");
    if (NULL != _vm_soc_svr_get_soc_id)
        return _vm_soc_svr_get_soc_id(hdl);
    return (VMINT)-1;
}