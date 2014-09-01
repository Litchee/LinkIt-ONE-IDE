#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_audio_register_interrupt_callback_t)(vm_audio_result_callback callback);
_vm_audio_register_interrupt_callback_t _vm_audio_register_interrupt_callback = NULL;

VMINT vm_audio_register_interrupt_callback(vm_audio_result_callback callback)
{
    if (NULL == _vm_audio_register_interrupt_callback)
        _vm_audio_register_interrupt_callback = (_vm_audio_register_interrupt_callback_t)vm_get_sym_entry("vm_audio_register_interrupt_callback");

    if (NULL != _vm_audio_register_interrupt_callback)
    	return _vm_audio_register_interrupt_callback(callback);

    return 0;
}
