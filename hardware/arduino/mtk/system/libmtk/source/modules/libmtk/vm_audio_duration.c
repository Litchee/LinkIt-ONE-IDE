#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_duration_t)(VMWSTR filename);
_vm_audio_duration_t _vm_audio_duration = NULL;

VMINT vm_audio_duration(VMWSTR filename)
{
    if (NULL == _vm_audio_duration)
        _vm_audio_duration = (_vm_audio_duration_t)vm_get_sym_entry("vm_audio_duration");

    if (NULL != _vm_audio_duration)
        return _vm_audio_duration(filename);

    return (VMINT )-1;
}
