#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_init_sync_t)(VMINT apn, VMINT port);
_vm_soc_svr_init_sync_t _vm_soc_svr_init_sync = NULL;

VMINT vm_soc_svr_init_sync(VMINT apn, VMINT port)
{
    if (NULL == _vm_soc_svr_init_sync)
        _vm_soc_svr_init_sync = (_vm_soc_svr_init_sync_t)vm_get_sym_entry("vm_soc_svr_init_sync");
    if (NULL != _vm_soc_svr_init_sync)
        return _vm_soc_svr_init_sync(apn,port);
    return (VMINT)-1;
}