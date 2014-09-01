#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_prof_query_list_t)(vm_wlan_prof_list_struct *prof_list);
_vm_wlan_prof_query_list_t _vm_wlan_prof_query_list = NULL;

VMINT vm_wlan_prof_query_list(vm_wlan_prof_list_struct *prof_list)
{
    if (NULL == _vm_wlan_prof_query_list)
        _vm_wlan_prof_query_list = (_vm_wlan_prof_query_list_t)vm_get_sym_entry("vm_wlan_prof_query_list");
    if (NULL != _vm_wlan_prof_query_list)
        return _vm_wlan_prof_query_list(prof_list);
    return (VMINT)-1;
}