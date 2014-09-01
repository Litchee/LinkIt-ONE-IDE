#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_midi_play_by_bytes_ex_t)( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) );
_vm_midi_play_by_bytes_ex_t _vm_midi_play_by_bytes_ex = NULL;

VMINT vm_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) )
{
    if (NULL == _vm_midi_play_by_bytes_ex)
        _vm_midi_play_by_bytes_ex = (_vm_midi_play_by_bytes_ex_t)vm_get_sym_entry("vm_midi_play_by_bytes_ex");

    if (NULL != _vm_midi_play_by_bytes_ex)
        return _vm_midi_play_by_bytes_ex(midibuf,len,start_time,repeat,path,f);

    return (VMINT )-1;
}
