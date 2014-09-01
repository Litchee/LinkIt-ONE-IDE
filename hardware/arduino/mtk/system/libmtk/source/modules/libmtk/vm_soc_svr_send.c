#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_send_t)(VMINT s_hdl, VMINT c_hdl, const void *data, VMUINT len);
_vm_soc_svr_send_t _vm_soc_svr_send = NULL;

VMINT vm_soc_svr_send(VMINT s_hdl, VMINT c_hdl, const void *data, VMUINT len)
{
    if (NULL == _vm_soc_svr_send)
        _vm_soc_svr_send = (_vm_soc_svr_send_t)vm_get_sym_entry("vm_soc_svr_send");
    if (NULL != _vm_soc_svr_send)
        return _vm_soc_svr_send(s_hdl,c_hdl,data,len);
    return (VMINT)-1;
}