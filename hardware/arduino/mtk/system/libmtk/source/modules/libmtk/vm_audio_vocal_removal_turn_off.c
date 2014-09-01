#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_vocal_removal_turn_off_t)(void);
_vm_audio_vocal_removal_turn_off_t _vm_audio_vocal_removal_turn_off = NULL;

VMINT vm_audio_vocal_removal_turn_off(void)
{
    if (NULL == _vm_audio_vocal_removal_turn_off)
        _vm_audio_vocal_removal_turn_off = (_vm_audio_vocal_removal_turn_off_t)vm_get_sym_entry("vm_audio_vocal_removal_turn_off");

    if (NULL != _vm_audio_vocal_removal_turn_off)
        return _vm_audio_vocal_removal_turn_off();

    return -1;
}
