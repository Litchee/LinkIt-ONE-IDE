#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_volume_t)(void);
_vm_get_volume_t _vm_get_volume = NULL;

VMINT vm_get_volume(void)
{
    if (NULL == _vm_get_volume)
        _vm_get_volume = (_vm_get_volume_t)vm_get_sym_entry("vm_get_volume");

    if (NULL != _vm_get_volume)
        return _vm_get_volume();

    return -1;
}
