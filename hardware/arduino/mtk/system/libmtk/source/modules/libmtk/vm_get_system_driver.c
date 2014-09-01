#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_get_system_driver_t)(void);
_vm_get_system_driver_t _vm_get_system_driver = NULL;

VMINT vm_get_system_driver(void)
{
    if (NULL == _vm_get_system_driver)
        _vm_get_system_driver = (_vm_get_system_driver_t)vm_get_sym_entry("vm_get_system_driver");

    if (NULL != _vm_get_system_driver)
        return _vm_get_system_driver();

    return (VMINT )-1;
}
