#include "vmsys.h"
#include "vmsensor.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_SRV_SENSOR_RESULT (*_vm_srv_sensor_disable_mode_t)(VM_SRV_SENSOR_HANDLE handle, VMUINT16 sensor_mode);
_vm_srv_sensor_disable_mode_t _vm_srv_sensor_disable_mode = NULL;

VM_SRV_SENSOR_RESULT vm_srv_sensor_disable_mode(VM_SRV_SENSOR_HANDLE handle, VMUINT16 sensor_mode)
{
    if (NULL == _vm_srv_sensor_disable_mode)
        _vm_srv_sensor_disable_mode = (_vm_srv_sensor_disable_mode_t)vm_get_sym_entry("vm_srv_sensor_disable_mode");

    if (NULL != _vm_srv_sensor_disable_mode)
        return _vm_srv_sensor_disable_mode(handle,sensor_mode);

    return (VMINT )-1;
}
