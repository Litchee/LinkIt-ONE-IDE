#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_set_service_name_t)(VMINT res_hd, VMWCHAR * name);
_vm_btspp_set_service_name_t _vm_btspp_set_service_name = NULL;
VMINT vm_btspp_set_service_name(VMINT res_hd, VMWCHAR * name)
{
    if (NULL == _vm_btspp_set_service_name)
        _vm_btspp_set_service_name = (_vm_btspp_set_service_name_t)vm_get_sym_entry("vm_btspp_set_service_name");

    if (NULL != _vm_btspp_set_service_name)
        return _vm_btspp_set_service_name(res_hd,name);

    return (VMINT)-1;
}
