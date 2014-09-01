#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_pause_t)(void (*f)(VMINT result));
_vm_audio_pause_t _vm_audio_pause = NULL;

VMINT vm_audio_pause(void (*f)(VMINT result))
{
    if (NULL == _vm_audio_pause)
        _vm_audio_pause = (_vm_audio_pause_t)vm_get_sym_entry("vm_audio_pause");

    if (NULL != _vm_audio_pause)
        return _vm_audio_pause(f);

    return (VMINT )-1;
}
