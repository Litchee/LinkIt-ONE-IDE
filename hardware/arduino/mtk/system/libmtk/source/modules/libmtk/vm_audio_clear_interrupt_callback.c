#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_audio_clear_interrupt_callback_t)(VMINT handle);
_vm_audio_clear_interrupt_callback_t _vm_audio_clear_interrupt_callback = NULL;

void vm_audio_clear_interrupt_callback(VMINT handle)
{
    if (NULL == _vm_audio_clear_interrupt_callback)
        _vm_audio_clear_interrupt_callback = (_vm_audio_clear_interrupt_callback_t)vm_get_sym_entry("vm_audio_clear_interrupt_callback");

    if (NULL != _vm_audio_clear_interrupt_callback)
        _vm_audio_clear_interrupt_callback(handle);
}
