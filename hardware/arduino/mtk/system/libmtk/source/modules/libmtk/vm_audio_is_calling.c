#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_is_calling_t)(void);
_vm_audio_is_calling_t _vm_audio_is_calling = NULL;

VMINT vm_audio_is_calling(void)
{
    if (NULL == _vm_audio_is_calling)
        _vm_audio_is_calling = (_vm_audio_is_calling_t)vm_get_sym_entry("vm_audio_is_calling");

    if (NULL != _vm_audio_is_calling)
        return _vm_audio_is_calling();

    return 0;
}
