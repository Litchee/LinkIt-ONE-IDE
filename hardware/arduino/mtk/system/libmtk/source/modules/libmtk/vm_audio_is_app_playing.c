#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_audio_is_app_playing_t)(void);
_vm_audio_is_app_playing_t _vm_audio_is_app_playing = NULL;

VMBOOL vm_audio_is_app_playing(void)
{
    if (NULL == _vm_audio_is_app_playing)
        _vm_audio_is_app_playing = (_vm_audio_is_app_playing_t)vm_get_sym_entry("vm_audio_is_app_playing");

    if (NULL != _vm_audio_is_app_playing)
        return _vm_audio_is_app_playing();

    return 0;
}
