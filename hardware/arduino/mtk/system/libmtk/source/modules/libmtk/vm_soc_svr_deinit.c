#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_deinit_t)(VMINT handle);
_vm_soc_svr_deinit_t _vm_soc_svr_deinit = NULL;

VMINT vm_soc_svr_deinit(VMINT handle)
{
    if (NULL == _vm_soc_svr_deinit)
        _vm_soc_svr_deinit = (_vm_soc_svr_deinit_t)vm_get_sym_entry("vm_soc_svr_deinit");
    if (NULL != _vm_soc_svr_deinit)
        return _vm_soc_svr_deinit(handle);
    return (VMINT)-1;
}