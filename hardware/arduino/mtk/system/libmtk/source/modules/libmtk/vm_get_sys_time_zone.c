#include "vmsys.h"
#include "vmsys.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef float (*_vm_get_sys_time_zone_t)(void);
_vm_get_sys_time_zone_t _vm_get_sys_time_zone = NULL;

float vm_get_sys_time_zone(void)
{
    float  ret = {-1};
    if (NULL == _vm_get_sys_time_zone)
        _vm_get_sys_time_zone = (_vm_get_sys_time_zone_t)vm_get_sym_entry("vm_get_sys_time_zone");

    if (NULL != _vm_get_sys_time_zone)
        return _vm_get_sys_time_zone();

    return ret;
}
