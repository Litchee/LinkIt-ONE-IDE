#include "vmsys.h"
#include "vmsettings.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_settings_set_tone_t)(vm_settings_tone_enum type, VMWCHAR* path);
_vm_settings_set_tone_t _vm_settings_set_tone = NULL;

VMINT vm_settings_set_tone(vm_settings_tone_enum type, VMWCHAR* path)
{
    if (NULL == _vm_settings_set_tone)
        _vm_settings_set_tone = (_vm_settings_set_tone_t)vm_get_sym_entry("vm_settings_set_tone");

    if (NULL != _vm_settings_set_tone)
        return _vm_settings_set_tone(type,path);

    return (VMINT )-1;
}
