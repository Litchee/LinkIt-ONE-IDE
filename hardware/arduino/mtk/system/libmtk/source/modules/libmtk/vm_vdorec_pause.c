#include "vmsys.h"
#include "vmvdorec.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vdorec_pause_t)(void);
_vm_vdorec_pause_t _vm_vdorec_pause = NULL;

VMINT vm_vdorec_pause(void)
{
    if (NULL == _vm_vdorec_pause)
        _vm_vdorec_pause = (_vm_vdorec_pause_t)vm_get_sym_entry("vm_vdorec_pause");

    if (NULL != _vm_vdorec_pause)
        return _vm_vdorec_pause();

    return (VMINT )-1;
}
