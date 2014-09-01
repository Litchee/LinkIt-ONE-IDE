#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_mixed_set_start_time_t)(VMINT handle, VMUINT start_time);
_vm_audio_mixed_set_start_time_t _vm_audio_mixed_set_start_time = NULL;

VMINT vm_audio_mixed_set_start_time(VMINT handle, VMUINT start_time)
{
    if (NULL == _vm_audio_mixed_set_start_time)
        _vm_audio_mixed_set_start_time = (_vm_audio_mixed_set_start_time_t)vm_get_sym_entry("vm_audio_mixed_set_start_time");

    if (NULL != _vm_audio_mixed_set_start_time)
        return _vm_audio_mixed_set_start_time(handle,start_time);
    return -1;
}
