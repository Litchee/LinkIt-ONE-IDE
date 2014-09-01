#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_midi_play_by_bytes_t)( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) );
_vm_midi_play_by_bytes_t _vm_midi_play_by_bytes = NULL;

VMINT vm_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) )
{
    if (NULL == _vm_midi_play_by_bytes)
        _vm_midi_play_by_bytes = (_vm_midi_play_by_bytes_t)vm_get_sym_entry("vm_midi_play_by_bytes");

    if (NULL != _vm_midi_play_by_bytes)
        return _vm_midi_play_by_bytes(midibuf,len,repeat,f);

    return (VMINT )-1;
}
