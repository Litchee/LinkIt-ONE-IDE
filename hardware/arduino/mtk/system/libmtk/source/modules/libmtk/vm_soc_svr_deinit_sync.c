#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_deinit_sync_t)(VMINT s_hdl);
_vm_soc_svr_deinit_sync_t _vm_soc_svr_deinit_sync = NULL;

VMINT vm_soc_svr_deinit_sync(VMINT s_hdl)
{
    if (NULL == _vm_soc_svr_deinit_sync)
        _vm_soc_svr_deinit_sync = (_vm_soc_svr_deinit_sync_t)vm_get_sym_entry("vm_soc_svr_deinit_sync");
    if (NULL != _vm_soc_svr_deinit_sync)
        return _vm_soc_svr_deinit_sync(s_hdl);
    return (VMINT)-1;
}