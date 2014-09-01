#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_query_t)(VMUINT32 prof_id, vm_wlan_prof_struct *prof);
_vm_wlan_prof_query_t _vm_wlan_prof_query = NULL;

VMINT vm_wlan_prof_query(VMUINT32 prof_id, vm_wlan_prof_struct *prof)
{
    if (NULL == _vm_wlan_prof_query)
        _vm_wlan_prof_query = (_vm_wlan_prof_query_t)vm_get_sym_entry("vm_wlan_prof_query");
    if (NULL != _vm_wlan_prof_query)
        return _vm_wlan_prof_query(prof_id,prof);
    return (VMINT)-1;
}