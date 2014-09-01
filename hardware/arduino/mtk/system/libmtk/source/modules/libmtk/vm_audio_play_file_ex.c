#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_play_file_ex_t)(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result));
_vm_audio_play_file_ex_t _vm_audio_play_file_ex = NULL;

VMINT vm_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
    if (NULL == _vm_audio_play_file_ex)
        _vm_audio_play_file_ex = (_vm_audio_play_file_ex_t)vm_get_sym_entry("vm_audio_play_file_ex");

    if (NULL != _vm_audio_play_file_ex)
        return _vm_audio_play_file_ex(filename,start_time,path,f);

    return (VMINT )-1;
}
