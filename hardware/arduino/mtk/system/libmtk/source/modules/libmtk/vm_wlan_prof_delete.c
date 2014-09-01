#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_delete_t)(VMUINT32 prof_id);
_vm_wlan_prof_delete_t _vm_wlan_prof_delete = NULL;

VMINT vm_wlan_prof_delete(VMUINT32 prof_id)
{
    if (NULL == _vm_wlan_prof_delete)
        _vm_wlan_prof_delete = (_vm_wlan_prof_delete_t)vm_get_sym_entry("vm_wlan_prof_delete");
    if (NULL != _vm_wlan_prof_delete)
        return _vm_wlan_prof_delete(prof_id);
    return (VMINT)-1;
}