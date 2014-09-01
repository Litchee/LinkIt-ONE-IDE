#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_read_t)(VMINT s_hdl, VMINT c_hdl, void *data, VMUINT len);
_vm_soc_svr_read_t _vm_soc_svr_read = NULL;

VMINT vm_soc_svr_read(VMINT s_hdl, VMINT c_hdl, void *data, VMUINT len)
{
    if (NULL == _vm_soc_svr_read)
        _vm_soc_svr_read = (_vm_soc_svr_read_t)vm_get_sym_entry("vm_soc_svr_read");
    if (NULL != _vm_soc_svr_read)
        return _vm_soc_svr_read(s_hdl,c_hdl,data,len);
    return (VMINT)-1;
}