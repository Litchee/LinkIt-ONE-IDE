#include "vmsys.h"
#include "vmsensor.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VM_SRV_SENSOR_RESULT (*_vm_srv_sensor_stop_listen_t)(VM_SRV_SENSOR_HANDLE handle);
_vm_srv_sensor_stop_listen_t _vm_srv_sensor_stop_listen = NULL;

VM_SRV_SENSOR_RESULT vm_srv_sensor_stop_listen(VM_SRV_SENSOR_HANDLE handle)
{
    if (NULL == _vm_srv_sensor_stop_listen)
        _vm_srv_sensor_stop_listen = (_vm_srv_sensor_stop_listen_t)vm_get_sym_entry("vm_srv_sensor_stop_listen");

    if (NULL != _vm_srv_sensor_stop_listen)
        return _vm_srv_sensor_stop_listen(handle);

    return (VMINT )-1;
}
