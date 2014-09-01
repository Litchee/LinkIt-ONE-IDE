#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_terminate_background_play_t)(void);
_vm_audio_terminate_background_play_t _vm_audio_terminate_background_play = NULL;

void vm_audio_terminate_background_play(void)
{
    if (NULL == _vm_audio_terminate_background_play)
        _vm_audio_terminate_background_play = (_vm_audio_terminate_background_play_t)vm_get_sym_entry("vm_audio_terminate_background_play");

    if (NULL != _vm_audio_terminate_background_play)
        _vm_audio_terminate_background_play();
}
