#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_play_beep_t)(void);
_vm_audio_play_beep_t _vm_audio_play_beep = NULL;

void vm_audio_play_beep(void)
{
    if (NULL == _vm_audio_play_beep)
        _vm_audio_play_beep = (_vm_audio_play_beep_t)vm_get_sym_entry("vm_audio_play_beep");

    if (NULL != _vm_audio_play_beep)
        _vm_audio_play_beep();   
}
