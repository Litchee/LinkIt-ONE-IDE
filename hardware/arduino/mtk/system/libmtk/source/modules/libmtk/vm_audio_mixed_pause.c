#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_mixed_pause_t)(VMINT handle);
_vm_audio_mixed_pause_t _vm_audio_mixed_pause = NULL;

VMINT vm_audio_mixed_pause(VMINT handle)
{
    if (NULL == _vm_audio_mixed_pause)
        _vm_audio_mixed_pause = (_vm_audio_mixed_pause_t)vm_get_sym_entry("vm_audio_mixed_pause");

    if (NULL != _vm_audio_mixed_pause)
        return _vm_audio_mixed_pause(handle);
    return -1;
}
