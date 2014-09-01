#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_init_t)(vm_wlan_prof_struct *profile);
_vm_wlan_prof_init_t _vm_wlan_prof_init = NULL;

VMINT vm_wlan_prof_init(vm_wlan_prof_struct *profile)
{
    if (NULL == _vm_wlan_prof_init)
        _vm_wlan_prof_init = (_vm_wlan_prof_init_t)vm_get_sym_entry("vm_wlan_prof_init");
    if (NULL != _vm_wlan_prof_init)
        return _vm_wlan_prof_init(profile);
    return (VMINT)-1;
}