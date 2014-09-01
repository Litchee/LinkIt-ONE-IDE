#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_play_bytes_t)(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result));
_vm_audio_play_bytes_t _vm_audio_play_bytes = NULL;

VMINT vm_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
    if (NULL == _vm_audio_play_bytes)
        _vm_audio_play_bytes = (_vm_audio_play_bytes_t)vm_get_sym_entry("vm_audio_play_bytes");

    if (NULL != _vm_audio_play_bytes)
        return _vm_audio_play_bytes(audio_data,len,format,start_time,path,f);

    return (VMINT )-1;
}
