#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_midi_stop_t)(VMINT handle);
_vm_midi_stop_t _vm_midi_stop = NULL;

void vm_midi_stop(VMINT handle)
{
    if (NULL == _vm_midi_stop)
        _vm_midi_stop = (_vm_midi_stop_t)vm_get_sym_entry("vm_midi_stop");

    if (NULL != _vm_midi_stop)
        _vm_midi_stop(handle);

    
}
