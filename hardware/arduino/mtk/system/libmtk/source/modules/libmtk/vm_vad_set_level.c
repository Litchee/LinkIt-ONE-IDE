#include "vmsys.h"
#include "vmvad.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMBOOL (*_vm_vad_set_level_t)(VMUINT8 level);
_vm_vad_set_level_t _vm_vad_set_level = NULL;

VMBOOL vm_vad_set_level(VMUINT8 level)
{
    if (NULL == _vm_vad_set_level)
        _vm_vad_set_level = (_vm_vad_set_level_t)vm_get_sym_entry("vm_vad_set_level");

    if (NULL != _vm_vad_set_level)
        return _vm_vad_set_level(level);

    return (VMBOOL)0;
}
