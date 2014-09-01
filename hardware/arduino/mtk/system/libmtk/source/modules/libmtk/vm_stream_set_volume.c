#include "vmsys.h"
#include "vmstream.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_stream_set_volume_t)(vm_stream_volume_enum type, VMUINT value);
_vm_stream_set_volume_t _vm_stream_set_volume = NULL;

void vm_stream_set_volume(vm_stream_volume_enum type, VMUINT value)
{
    if (NULL == _vm_stream_set_volume)
        _vm_stream_set_volume = (_vm_stream_set_volume_t)vm_get_sym_entry("vm_stream_set_volume");

    if (NULL != _vm_stream_set_volume)
        _vm_stream_set_volume(type, value);
}
