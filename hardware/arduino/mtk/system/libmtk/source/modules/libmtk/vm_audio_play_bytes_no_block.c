#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_play_bytes_no_block_t)(void *audio_data, VMUINT len, VMUINT8 format, VMUINT path, void (*f)(VMINT result));
_vm_audio_play_bytes_no_block_t _vm_audio_play_bytes_no_block = NULL;

VMINT vm_audio_play_bytes_no_block(void *audio_data, VMUINT len, VMUINT8 format, VMUINT path, void (*f)(VMINT result))
{
    if (NULL == _vm_audio_play_bytes_no_block)
        _vm_audio_play_bytes_no_block = (_vm_audio_play_bytes_no_block_t)vm_get_sym_entry("vm_audio_play_bytes_no_block");

    if (NULL != _vm_audio_play_bytes_no_block)
       return _vm_audio_play_bytes_no_block(audio_data, len, format, path, f);
		return -1;    
}
