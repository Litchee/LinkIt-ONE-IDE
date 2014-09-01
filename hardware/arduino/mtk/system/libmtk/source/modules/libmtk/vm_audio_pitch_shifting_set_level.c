#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_pitch_shifting_set_level_t)(VMINT16 level);
_vm_audio_pitch_shifting_set_level_t _vm_audio_pitch_shifting_set_level = NULL;

VMINT vm_audio_pitch_shifting_set_level(VMINT16 level)
{
    if (NULL == _vm_audio_pitch_shifting_set_level)
        _vm_audio_pitch_shifting_set_level = (_vm_audio_pitch_shifting_set_level_t)vm_get_sym_entry("vm_audio_pitch_shifting_set_level");

    if (NULL != _vm_audio_pitch_shifting_set_level)
        return _vm_audio_pitch_shifting_set_level(level);

    return -1;
}
