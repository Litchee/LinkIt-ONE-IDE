#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_mixed_play_t)(VMINT handle);
_vm_audio_mixed_play_t _vm_audio_mixed_play = NULL;

VMINT vm_audio_mixed_play(VMINT handle)
{
    if (NULL == _vm_audio_mixed_play)
        _vm_audio_mixed_play = (_vm_audio_mixed_play_t)vm_get_sym_entry("vm_audio_mixed_play");

    if (NULL != _vm_audio_mixed_play)
        return _vm_audio_mixed_play(handle);
    return -1;
}
