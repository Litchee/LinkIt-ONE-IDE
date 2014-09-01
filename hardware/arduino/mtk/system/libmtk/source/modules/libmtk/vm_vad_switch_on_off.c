#include "vmsys.h"
#include "vmvad.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_vad_switch_on_off_t)(VMBOOL on, void* param);
_vm_vad_switch_on_off_t _vm_vad_switch_on_off = NULL;

VMBOOL vm_vad_switch_on_off(VMBOOL on, void* param)
{
    if (NULL == _vm_vad_switch_on_off)
        _vm_vad_switch_on_off = (_vm_vad_switch_on_off_t)vm_get_sym_entry("vm_vad_switch_on_off");

    if (NULL != _vm_vad_switch_on_off)
        return _vm_vad_switch_on_off(on,param);

    return (VMBOOL)0;
}

