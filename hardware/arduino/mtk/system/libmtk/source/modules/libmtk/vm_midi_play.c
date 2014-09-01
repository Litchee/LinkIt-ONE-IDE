#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_midi_play_t)(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event));
_vm_midi_play_t _vm_midi_play = NULL;

VMINT vm_midi_play(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event))
{
    if (NULL == _vm_midi_play)
        _vm_midi_play = (_vm_midi_play_t)vm_get_sym_entry("vm_midi_play");

    if (NULL != _vm_midi_play)
        return _vm_midi_play(resid,repeat,f);

    return (VMINT )-1;
}
