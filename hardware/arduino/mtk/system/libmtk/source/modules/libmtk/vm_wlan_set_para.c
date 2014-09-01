#include "vmsys.h"
#include "vmnwsetting.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_wlan_set_para_t)(vm_wlan_set_mode_enum mode, void *para, VMINT32 flag);
_vm_wlan_set_para_t _vm_wlan_set_para = NULL;

VMINT vm_wlan_set_para(vm_wlan_set_mode_enum mode, void *para, VMINT32 flag)
{
    if (NULL == _vm_wlan_set_para)
        _vm_wlan_set_para = (_vm_wlan_set_para_t)vm_get_sym_entry("vm_wlan_set_para");
    if (NULL != _vm_wlan_set_para)
        return _vm_wlan_set_para(mode,para,flag);
    return (VMINT)-100;
}