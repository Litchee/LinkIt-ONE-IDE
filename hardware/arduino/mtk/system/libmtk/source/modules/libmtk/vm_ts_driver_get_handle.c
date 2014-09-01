#include "vmsys.h"
#include "vmtsloader.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_ts_driver_get_handle_t)(void);
_vm_ts_driver_get_handle_t _vm_ts_driver_get_handle = NULL;
VMINT vm_ts_driver_get_handle(void)
{
    if (NULL == _vm_ts_driver_get_handle)
        _vm_ts_driver_get_handle = (_vm_ts_driver_get_handle_t)vm_get_sym_entry("vm_ts_driver_get_handle");

    if (NULL != _vm_ts_driver_get_handle)
        return _vm_ts_driver_get_handle();

    return -1;
}

