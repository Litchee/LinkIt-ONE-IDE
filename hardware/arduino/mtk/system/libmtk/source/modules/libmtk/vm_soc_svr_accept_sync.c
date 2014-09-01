#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_accept_sync_t)(VMINT s_hdl, vm_sockaddr_struct *addr);
_vm_soc_svr_accept_sync_t _vm_soc_svr_accept_sync = NULL;

VMINT vm_soc_svr_accept_sync(VMINT s_hdl, vm_sockaddr_struct *addr)
{
    if (NULL == _vm_soc_svr_accept_sync)
        _vm_soc_svr_accept_sync = (_vm_soc_svr_accept_sync_t)vm_get_sym_entry("vm_soc_svr_accept_sync");
    if (NULL != _vm_soc_svr_accept_sync)
        return _vm_soc_svr_accept_sync(s_hdl,addr);
    return (VMINT)-1;
}