#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_perfer_t)(VMINT disable);
_vm_wlan_perfer_t _vm_wlan_perfer = NULL;
VMINT vm_wlan_perfer(VMINT disable)
{
    if (NULL == _vm_wlan_perfer)
        _vm_wlan_perfer = (_vm_wlan_perfer_t)vm_get_sym_entry("vm_wlan_perfer");

    if (NULL != _vm_wlan_perfer)
        return _vm_wlan_perfer(disable);

    return -1;

}


