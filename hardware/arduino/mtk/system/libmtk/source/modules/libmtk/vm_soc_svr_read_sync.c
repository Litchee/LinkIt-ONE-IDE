#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_read_sync_t)(VMINT c_hdl, void *data, VMUINT len);
_vm_soc_svr_read_sync_t _vm_soc_svr_read_sync = NULL;

VMINT vm_soc_svr_read_sync(VMINT c_hdl, void *data, VMUINT len)
{
    if (NULL == _vm_soc_svr_read_sync)
        _vm_soc_svr_read_sync = (_vm_soc_svr_read_sync_t)vm_get_sym_entry("vm_soc_svr_read_sync");
    if (NULL != _vm_soc_svr_read_sync)
        return _vm_soc_svr_read_sync(c_hdl,data,len);
    return (VMINT)-1;
}