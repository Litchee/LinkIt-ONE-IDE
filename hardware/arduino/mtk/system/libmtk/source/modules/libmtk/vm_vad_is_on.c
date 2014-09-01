#include "vmsys.h"
#include "vmvad.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_vad_is_on_t)(void);
_vm_vad_is_on_t _vm_vad_is_on = NULL;

VMBOOL vm_vad_is_on(void)
{
    if (NULL == _vm_vad_is_on)
        _vm_vad_is_on = (_vm_vad_is_on_t)vm_get_sym_entry("vm_vad_is_on");

    if (NULL != _vm_vad_is_on)
        return _vm_vad_is_on();

    return (VMBOOL)0;
}
