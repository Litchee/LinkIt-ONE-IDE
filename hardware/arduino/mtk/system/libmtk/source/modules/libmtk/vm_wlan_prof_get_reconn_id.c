#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_get_reconn_id_t)(VMUINT32 *prof_id);
_vm_wlan_prof_get_reconn_id_t _vm_wlan_prof_get_reconn_id = NULL;

VMINT vm_wlan_prof_get_reconn_id(VMUINT32 *prof_id)
{
    if (NULL == _vm_wlan_prof_get_reconn_id)
        _vm_wlan_prof_get_reconn_id = (_vm_wlan_prof_get_reconn_id_t)vm_get_sym_entry("vm_wlan_prof_get_reconn_id");
    if (NULL != _vm_wlan_prof_get_reconn_id)
        return _vm_wlan_prof_get_reconn_id(prof_id);
    return (VMINT)-1;
}