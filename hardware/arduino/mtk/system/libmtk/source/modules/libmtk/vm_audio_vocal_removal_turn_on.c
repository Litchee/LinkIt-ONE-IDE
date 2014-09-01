#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_vocal_removal_turn_on_t)(void);
_vm_audio_vocal_removal_turn_on_t _vm_audio_vocal_removal_turn_on = NULL;

VMINT vm_audio_vocal_removal_turn_on(void)
{
    if (NULL == _vm_audio_vocal_removal_turn_on)
        _vm_audio_vocal_removal_turn_on = (_vm_audio_vocal_removal_turn_on_t)vm_get_sym_entry("vm_audio_vocal_removal_turn_on");

    if (NULL != _vm_audio_vocal_removal_turn_on)
        return _vm_audio_vocal_removal_turn_on();

    return -1;
}
