#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_mixed_close_all_t)(void);
_vm_audio_mixed_close_all_t _vm_audio_mixed_close_all = NULL;

void vm_audio_mixed_close_all(void)
{
    if (NULL == _vm_audio_mixed_close_all)
        _vm_audio_mixed_close_all = (_vm_audio_mixed_close_all_t)vm_get_sym_entry("vm_audio_mixed_close_all");

    if (NULL != _vm_audio_mixed_close_all)
        _vm_audio_mixed_close_all();
}
