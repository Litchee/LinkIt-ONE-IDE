#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_get_para_t)(vm_wlan_set_mode_enum mode, void *para);
_vm_wlan_get_para_t _vm_wlan_get_para = NULL;

VMINT vm_wlan_get_para(vm_wlan_set_mode_enum mode, void *para)
{
    if (NULL == _vm_wlan_get_para)
        _vm_wlan_get_para = (_vm_wlan_get_para_t)vm_get_sym_entry("vm_wlan_get_para");
    if (NULL != _vm_wlan_get_para)
        return _vm_wlan_get_para(mode,para);
    return (VMINT)-100;
}