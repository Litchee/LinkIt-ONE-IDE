#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_soc_svr_init_t)(VMINT apn, VMINT port, void *user_data, void (*callback)(VMINT handle, VMINT event, VMINT param, void *user_data));
_vm_soc_svr_init_t _vm_soc_svr_init = NULL;

VMINT vm_soc_svr_init(VMINT apn, VMINT port, void *user_data, void (*callback)(VMINT handle, VMINT event, VMINT param, void *user_data))
{
    if (NULL == _vm_soc_svr_init)
        _vm_soc_svr_init = (_vm_soc_svr_init_t)vm_get_sym_entry("vm_soc_svr_init");
    if (NULL != _vm_soc_svr_init)
        return _vm_soc_svr_init(apn,port,user_data,callback);
    return (VMINT)-1;
}