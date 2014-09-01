#include "vmsys.h"
#include "vmmm.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_set_volume_t)(VMINT volume);
_vm_set_volume_t _vm_set_volume = NULL;

void vm_set_volume(VMINT volume)
{
    if (NULL == _vm_set_volume)
        _vm_set_volume = (_vm_set_volume_t)vm_get_sym_entry("vm_set_volume");

    if (NULL != _vm_set_volume)
        _vm_set_volume(volume);

    
}
