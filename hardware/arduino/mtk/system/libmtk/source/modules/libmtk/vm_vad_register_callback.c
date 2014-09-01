#include "vmsys.h"
#include "vmvad.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_vad_register_callback_t)(vm_vad_msg_hdlr callback);
_vm_vad_register_callback_t _vm_vad_register_callback = NULL;

void vm_vad_register_callback(vm_vad_msg_hdlr callback)
{
    if (NULL == _vm_vad_register_callback)
        _vm_vad_register_callback = (_vm_vad_register_callback_t)vm_get_sym_entry("vm_vad_register_callback");

    if (NULL != _vm_vad_register_callback)
        _vm_vad_register_callback(callback);
}
