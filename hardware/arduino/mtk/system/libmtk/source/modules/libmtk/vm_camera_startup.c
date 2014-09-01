#include "vmsys.h"
#include "vmstdlib.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_vm_camera_startup_t)(void);
_vm_vm_camera_startup_t _vm_camera_startup = NULL;
VMINT vm_camera_startup(void)
{
    if (NULL == _vm_camera_startup)
        _vm_camera_startup = (_vm_vm_camera_startup_t)vm_get_sym_entry("vm_camera_startup");

    if (NULL != _vm_camera_startup)
        return _vm_camera_startup();

    return -1;
}
