#include "vmsys.h"
#include "vmtsloader.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef void* (*_vm_ts_driver_get_mem_t)(VMINT handle);
_vm_ts_driver_get_mem_t _vm_ts_driver_get_mem = NULL;
void* vm_ts_driver_get_mem(VMINT handle)
{
    if (NULL == _vm_ts_driver_get_mem)
        _vm_ts_driver_get_mem = (_vm_ts_driver_get_mem_t)vm_get_sym_entry("vm_ts_driver_get_mem");

    if (NULL != _vm_ts_driver_get_mem)
        return _vm_ts_driver_get_mem(handle);

    return (void*)NULL;
}

