#include "vmsys.h"
#include "vmbtspp.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_btspp_set_security_level_t)(VMINT res_hd, VMINT level);
_vm_btspp_set_security_level_t _vm_btspp_set_security_level = NULL;
VMINT vm_btspp_set_security_level(VMINT res_hd, VMINT level)
{
    if (NULL == _vm_btspp_set_security_level)
        _vm_btspp_set_security_level = (_vm_btspp_set_security_level_t)vm_get_sym_entry("vm_btspp_set_security_level");

    if (NULL != _vm_btspp_set_security_level)
        return _vm_btspp_set_security_level(res_hd,level);

    return (VMINT)-1;
}
