#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_mixed_close_t)(VMINT handle);
_vm_audio_mixed_close_t _vm_audio_mixed_close = NULL;

void vm_audio_mixed_close(VMINT handle)
{
    if (NULL == _vm_audio_mixed_close)
        _vm_audio_mixed_close = (_vm_audio_mixed_close_t)vm_get_sym_entry("vm_audio_mixed_close");

    if (NULL != _vm_audio_mixed_close)
        _vm_audio_mixed_close(handle);
}
