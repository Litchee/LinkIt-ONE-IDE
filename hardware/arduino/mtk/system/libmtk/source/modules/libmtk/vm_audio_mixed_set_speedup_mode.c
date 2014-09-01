#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_mixed_set_speedup_mode_t)(VMBOOL mode);
_vm_audio_mixed_set_speedup_mode_t _vm_audio_mixed_set_speedup_mode = NULL;

void vm_audio_mixed_set_speedup_mode(VMBOOL mode)
{
    if (NULL == _vm_audio_mixed_set_speedup_mode)
        _vm_audio_mixed_set_speedup_mode = (_vm_audio_mixed_set_speedup_mode_t)vm_get_sym_entry("vm_audio_mixed_set_speedup_mode");

    if (NULL != _vm_audio_mixed_set_speedup_mode)
        _vm_audio_mixed_set_speedup_mode(mode);
}
