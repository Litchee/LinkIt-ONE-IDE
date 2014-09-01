#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_stop_t)(void (*f)(VMINT result));
_vm_audio_stop_t _vm_audio_stop = NULL;

VMINT vm_audio_stop(void (*f)(VMINT result))
{
    if (NULL == _vm_audio_stop)
        _vm_audio_stop = (_vm_audio_stop_t)vm_get_sym_entry("vm_audio_stop");

    if (NULL != _vm_audio_stop)
        return _vm_audio_stop(f);

    return (VMINT )-1;
}
