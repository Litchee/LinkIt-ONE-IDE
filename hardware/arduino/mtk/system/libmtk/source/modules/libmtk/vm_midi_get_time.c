#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_midi_get_time_t)(VMINT handle, VMUINT *current_time);
_vm_midi_get_time_t _vm_midi_get_time = NULL;

VMINT vm_midi_get_time(VMINT handle, VMUINT *current_time)
{
    if (NULL == _vm_midi_get_time)
        _vm_midi_get_time = (_vm_midi_get_time_t)vm_get_sym_entry("vm_midi_get_time");

    if (NULL != _vm_midi_get_time)
        return _vm_midi_get_time(handle,current_time);

    return (VMINT )-1;
}
