#include "vmsys.h"
#include "vmtsloader.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;


typedef VMINT (*_vm_ts_driver_load_t)(VMWSTR fileName, VMINT size);
_vm_ts_driver_load_t _vm_ts_driver_load = NULL;
VMINT vm_ts_driver_load(VMWSTR fileName, VMINT size)
{
    if (NULL == _vm_ts_driver_load)
        _vm_ts_driver_load = (_vm_ts_driver_load_t)vm_get_sym_entry("vm_ts_driver_load");

    if (NULL != _vm_ts_driver_load)
        return _vm_ts_driver_load(fileName, size);

    return (VMINT )-1;
}


