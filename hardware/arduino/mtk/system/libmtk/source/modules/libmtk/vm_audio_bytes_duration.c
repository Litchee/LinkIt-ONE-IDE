#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_bytes_duration_t)(void *audio_data, VMUINT len, VMUINT8 format);
_vm_audio_bytes_duration_t _vm_audio_bytes_duration = NULL;

VMINT vm_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format)
{
    if (NULL == _vm_audio_bytes_duration)
        _vm_audio_bytes_duration = (_vm_audio_bytes_duration_t)vm_get_sym_entry("vm_audio_bytes_duration");

    if (NULL != _vm_audio_bytes_duration)
        return _vm_audio_bytes_duration(audio_data,len,format);

    return (VMINT )-1;
}
