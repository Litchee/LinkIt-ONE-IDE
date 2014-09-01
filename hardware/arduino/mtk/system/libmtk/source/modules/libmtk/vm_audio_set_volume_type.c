#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_set_volume_type_t)(VMINT type);
_vm_audio_set_volume_type_t _vm_audio_set_volume_type = NULL;

VMINT vm_audio_set_volume_type(VMINT type)
{
    if (NULL == _vm_audio_set_volume_type)
        _vm_audio_set_volume_type = (_vm_audio_set_volume_type_t)vm_get_sym_entry("vm_audio_set_volume_type");

    if (NULL != _vm_audio_set_volume_type)
        return _vm_audio_set_volume_type(type);

    return 0;
}
