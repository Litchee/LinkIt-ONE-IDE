#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_roaming_get_t)(VMINT *is_roaming);
_vm_wlan_roaming_get_t _vm_wlan_roaming_get = NULL;

VMINT vm_wlan_roaming_get(VMINT *is_roaming)
{
    if (NULL == _vm_wlan_roaming_get)
        _vm_wlan_roaming_get = (_vm_wlan_roaming_get_t)vm_get_sym_entry("vm_wlan_roaming_get");
    if (NULL != _vm_wlan_roaming_get)
        return _vm_wlan_roaming_get(is_roaming);
    return (VMINT)-1;
}