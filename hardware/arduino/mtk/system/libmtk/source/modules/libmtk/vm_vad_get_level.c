#include "vmsys.h"
#include "vmvad.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMUINT8 (*_vm_vad_get_level_t)(void);
_vm_vad_get_level_t _vm_vad_get_level = NULL;

VMUINT8 vm_vad_get_level(void)
{
    if (NULL == _vm_vad_get_level)
        _vm_vad_get_level = (_vm_vad_get_level_t)vm_get_sym_entry("vm_vad_get_level");

    if (NULL != _vm_vad_get_level)
        return _vm_vad_get_level();

    return (VMUINT8)0;
}
