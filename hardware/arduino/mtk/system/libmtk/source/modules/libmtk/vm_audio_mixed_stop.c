#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_mixed_stop_t)(VMINT handle);
_vm_audio_mixed_stop_t _vm_audio_mixed_stop = NULL;

void vm_audio_mixed_stop(VMINT handle)
{
    if (NULL == _vm_audio_mixed_stop)
        _vm_audio_mixed_stop = (_vm_audio_mixed_stop_t)vm_get_sym_entry("vm_audio_mixed_stop");

    if (NULL != _vm_audio_mixed_stop)
        _vm_audio_mixed_stop(handle);
}
