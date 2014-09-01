#include "vmsys.h"
#include "vmtsloader.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void (*_vm_ts_driver_free_t)(VMINT handle);
_vm_ts_driver_free_t _vm_ts_driver_free = NULL;
void vm_ts_driver_free(VMINT handle)
{
    if (NULL == _vm_ts_driver_free)
        _vm_ts_driver_free = (_vm_ts_driver_free_t)vm_get_sym_entry("vm_ts_driver_free");

    if (NULL != _vm_ts_driver_free)
        _vm_ts_driver_free(handle);
}
