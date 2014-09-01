#include "vmsys.h"
#include "vmnvram.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_nvram_get_data_t)(vm_nvram_sensor_lid id, void* buff, VMUINT size);
_vm_nvram_get_data_t _vm_nvram_get_data = NULL;
VMINT vm_nvram_get_data(vm_nvram_sensor_lid id, void* buff, VMUINT size)
{
    if (NULL == _vm_nvram_get_data)
        _vm_nvram_get_data = (_vm_nvram_get_data_t)vm_get_sym_entry("vm_nvram_get_data");

    if (NULL != _vm_nvram_get_data)
        return _vm_nvram_get_data(id, buff, size);
        
    return -1;
}

