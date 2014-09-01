#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_mode_get_t)(void);
_vm_wlan_mode_get_t _vm_wlan_mode_get = NULL;

VMINT vm_wlan_mode_get(void)
{
    if (NULL == _vm_wlan_mode_get)
        _vm_wlan_mode_get = (_vm_wlan_mode_get_t)vm_get_sym_entry("vm_wlan_mode_get");
    if (NULL != _vm_wlan_mode_get)
        return _vm_wlan_mode_get();
    return (VMINT)-1;
}