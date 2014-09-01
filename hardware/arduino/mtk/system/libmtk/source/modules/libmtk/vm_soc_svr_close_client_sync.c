#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_close_client_sync_t)(VMINT c_hdl);
_vm_soc_svr_close_client_sync_t _vm_soc_svr_close_client_sync = NULL;

VMINT vm_soc_svr_close_client_sync(VMINT c_hdl)
{
    if (NULL == _vm_soc_svr_close_client_sync)
        _vm_soc_svr_close_client_sync = (_vm_soc_svr_close_client_sync_t)vm_get_sym_entry("vm_soc_svr_close_client_sync");
    if (NULL != _vm_soc_svr_close_client_sync)
        return _vm_soc_svr_close_client_sync(c_hdl);
    return (VMINT)-1;
}