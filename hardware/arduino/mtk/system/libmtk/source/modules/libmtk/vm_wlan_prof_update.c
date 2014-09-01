#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_update_t)(VMUINT32 prof_id, vm_wlan_prof_struct *prof, VMUINT32 prof_fields);
_vm_wlan_prof_update_t _vm_wlan_prof_update = NULL;

VMINT vm_wlan_prof_update(VMUINT32 prof_id, vm_wlan_prof_struct *prof, VMUINT32 prof_fields)
{
    if (NULL == _vm_wlan_prof_update)
        _vm_wlan_prof_update = (_vm_wlan_prof_update_t)vm_get_sym_entry("vm_wlan_prof_update");
    if (NULL != _vm_wlan_prof_update)
        return _vm_wlan_prof_update(prof_id,prof,prof_fields);
    return (VMINT)-1;
}