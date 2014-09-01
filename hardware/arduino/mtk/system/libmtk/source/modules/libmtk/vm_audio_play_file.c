#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_play_file_t)(VMWSTR filename, void (*f)(VMINT result));
_vm_audio_play_file_t _vm_audio_play_file = NULL;

VMINT vm_audio_play_file(VMWSTR filename, void (*f)(VMINT result))
{
    if (NULL == _vm_audio_play_file)
        _vm_audio_play_file = (_vm_audio_play_file_t)vm_get_sym_entry("vm_audio_play_file");

    if (NULL != _vm_audio_play_file)
        return _vm_audio_play_file(filename,f);

    return (VMINT )-1;
}
