#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_get_time_t)(void);
_vm_audio_get_time_t _vm_audio_get_time = NULL;

VMINT vm_audio_get_time(void)
{
    if (NULL == _vm_audio_get_time)
        _vm_audio_get_time = (_vm_audio_get_time_t)vm_get_sym_entry("vm_audio_get_time");

    if (NULL != _vm_audio_get_time)
        return _vm_audio_get_time();

    return (VMINT )-1;
}
