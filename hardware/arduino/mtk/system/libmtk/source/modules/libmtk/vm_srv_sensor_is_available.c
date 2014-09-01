#include "vmsys.h"
#include "vmsensor.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_sensor_is_available_t)(vm_srv_sensor_type_enum sensor_type);
_vm_srv_sensor_is_available_t _vm_srv_sensor_is_available = NULL;

VMINT vm_srv_sensor_is_available(vm_srv_sensor_type_enum sensor_type)
{
    if (NULL == _vm_srv_sensor_is_available)
        _vm_srv_sensor_is_available = (_vm_srv_sensor_is_available_t)vm_get_sym_entry("vm_srv_sensor_is_available");

    if (NULL != _vm_srv_sensor_is_available)
        return _vm_srv_sensor_is_available(sensor_type);

    return (VMINT )-1;
}
