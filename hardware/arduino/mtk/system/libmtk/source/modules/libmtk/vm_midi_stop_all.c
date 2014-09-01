#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_midi_stop_all_t)(void);
_vm_midi_stop_all_t _vm_midi_stop_all = NULL;

void vm_midi_stop_all(void)
{
    if (NULL == _vm_midi_stop_all)
        _vm_midi_stop_all = (_vm_midi_stop_all_t)vm_get_sym_entry("vm_midi_stop_all");

    if (NULL != _vm_midi_stop_all)
        _vm_midi_stop_all();

    
}
