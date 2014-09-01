#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_resume_bg_play_t)(void);
_vm_audio_resume_bg_play_t _vm_audio_resume_bg_play = NULL;

void vm_audio_resume_bg_play(void)
{
    if (NULL == _vm_audio_resume_bg_play)
        _vm_audio_resume_bg_play = (_vm_audio_resume_bg_play_t)vm_get_sym_entry("vm_audio_resume_bg_play");

    if (NULL != _vm_audio_resume_bg_play)
        _vm_audio_resume_bg_play();
}
