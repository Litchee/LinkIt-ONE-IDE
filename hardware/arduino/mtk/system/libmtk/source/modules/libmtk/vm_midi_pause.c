#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_midi_pause_t)(VMINT handle);
_vm_midi_pause_t _vm_midi_pause = NULL;

VMINT vm_midi_pause(VMINT handle)
{
    if (NULL == _vm_midi_pause)
        _vm_midi_pause = (_vm_midi_pause_t)vm_get_sym_entry("vm_midi_pause");

    if (NULL != _vm_midi_pause)
        return _vm_midi_pause(handle);

    return (VMINT )-1;
}
