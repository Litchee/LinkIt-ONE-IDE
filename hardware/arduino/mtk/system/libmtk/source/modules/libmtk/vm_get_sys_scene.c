#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_sys_scene_t)(void);
_vm_get_sys_scene_t _vm_get_sys_scene = NULL;

VMINT vm_get_sys_scene(void)
{
    if (NULL == _vm_get_sys_scene)
        _vm_get_sys_scene = (_vm_get_sys_scene_t)vm_get_sym_entry("vm_get_sys_scene");

    if (NULL != _vm_get_sys_scene)
        return _vm_get_sys_scene();

    return (VMINT )-1;
}
