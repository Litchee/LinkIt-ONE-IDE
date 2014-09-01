#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_status_t)(void);
_vm_wlan_status_t _vm_wlan_status = NULL;

VMINT vm_wlan_status(void)
{
    if (NULL == _vm_wlan_status)
        _vm_wlan_status = (_vm_wlan_status_t)vm_get_sym_entry("vm_wlan_status");
    if (NULL != _vm_wlan_status)
        return _vm_wlan_status();
    return (VMINT)-1;
}