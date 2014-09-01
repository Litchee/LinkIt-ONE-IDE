#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_mixed_open_t)(vm_auido_mixed_open_struct* mixed_play);
_vm_audio_mixed_open_t _vm_audio_mixed_open = NULL;

VMINT vm_audio_mixed_open(vm_auido_mixed_open_struct* mixed_open)
{
    if (NULL == _vm_audio_mixed_open)
        _vm_audio_mixed_open = (_vm_audio_mixed_open_t)vm_get_sym_entry("vm_audio_mixed_open");

    if (NULL != _vm_audio_mixed_open)
        return _vm_audio_mixed_open(mixed_open);
    return -1;
}
