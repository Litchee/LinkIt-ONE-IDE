#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_close_client_t)(VMINT c_hdl);
_vm_soc_svr_close_client_t _vm_soc_svr_close_client = NULL;

VMINT vm_soc_svr_close_client(VMINT c_hdl)
{
    if (NULL == _vm_soc_svr_close_client)
        _vm_soc_svr_close_client = (_vm_soc_svr_close_client_t)vm_get_sym_entry("vm_soc_svr_close_client");
    if (NULL != _vm_soc_svr_close_client)
        return _vm_soc_svr_close_client(c_hdl);
    return (VMINT)-1;
}