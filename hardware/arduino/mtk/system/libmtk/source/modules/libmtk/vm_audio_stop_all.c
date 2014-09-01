#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_stop_all_t)(void);
_vm_audio_stop_all_t _vm_audio_stop_all = NULL;

VMINT vm_audio_stop_all(void) 
{
    if (NULL == _vm_audio_stop_all)
        _vm_audio_stop_all = (_vm_audio_stop_all_t)vm_get_sym_entry("vm_audio_stop_all");

    if (NULL != _vm_audio_stop_all)
        return _vm_audio_stop_all();

    return -1;
}
