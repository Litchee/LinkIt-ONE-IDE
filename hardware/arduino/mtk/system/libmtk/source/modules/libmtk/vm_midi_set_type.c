#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_midi_set_type_t)(VMINT type);
_vm_midi_set_type_t _vm_midi_set_type = NULL;

void vm_midi_set_type(VMINT type)
{
    if (NULL == _vm_midi_set_type)
        _vm_midi_set_type = (_vm_midi_set_type_t)vm_get_sym_entry("vm_midi_set_type");

    if (NULL != _vm_midi_set_type)
        _vm_midi_set_type(type);
}
