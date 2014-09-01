#include "vmsys.h"
#include "vmio.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_is_support_camera_sensor_t)(void);
_vm_is_support_camera_sensor_t _vm_is_support_camera_sensor = NULL;

VMINT vm_is_support_camera_sensor(void)
{
    if (NULL == _vm_is_support_camera_sensor)
        _vm_is_support_camera_sensor = (_vm_is_support_camera_sensor_t)vm_get_sym_entry("vm_is_support_camera_sensor");

    if (NULL != _vm_is_support_camera_sensor)
        return _vm_is_support_camera_sensor();

    return (VMINT )-1;
}
