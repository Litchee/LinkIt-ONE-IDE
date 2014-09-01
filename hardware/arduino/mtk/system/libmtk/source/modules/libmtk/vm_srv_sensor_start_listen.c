#include "vmsys.h"
#include "vmsensor.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_srv_sensor_start_listen_t)(vm_srv_sensor_type_enum type, void *option, VM_SRV_SENSOR_EVENT_HDLR event_hdlr, void *user_data);
_vm_srv_sensor_start_listen_t _vm_srv_sensor_start_listen = NULL;

VM_SRV_SENSOR_HANDLE vm_srv_sensor_start_listen(vm_srv_sensor_type_enum type, void *option, VM_SRV_SENSOR_EVENT_HDLR event_hdlr, void *user_data)
{
    if (NULL == _vm_srv_sensor_start_listen)
        _vm_srv_sensor_start_listen = (_vm_srv_sensor_start_listen_t)vm_get_sym_entry("vm_srv_sensor_start_listen");

    if (NULL != _vm_srv_sensor_start_listen)
        return _vm_srv_sensor_start_listen(type,option,event_hdlr,user_data);

    return (VMINT )-1;
}
