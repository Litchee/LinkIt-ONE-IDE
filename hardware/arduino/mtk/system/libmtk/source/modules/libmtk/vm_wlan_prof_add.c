#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_add_t)(const vm_wlan_prof_struct *prof, VMUINT32 *prof_id);
_vm_wlan_prof_add_t _vm_wlan_prof_add = NULL;

VMINT vm_wlan_prof_add(const vm_wlan_prof_struct *prof, VMUINT32 *prof_id)
{
    if (NULL == _vm_wlan_prof_add)
        _vm_wlan_prof_add = (_vm_wlan_prof_add_t)vm_get_sym_entry("vm_wlan_prof_add");
    if (NULL != _vm_wlan_prof_add)
        return _vm_wlan_prof_add(prof,prof_id);
    return (VMINT)-1;
}