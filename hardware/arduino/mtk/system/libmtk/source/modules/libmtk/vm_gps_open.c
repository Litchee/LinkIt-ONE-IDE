#include "vmsys.h"
#include "vmgps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_gps_open_t)(VMUINT period, vm_gps_type_enum type, VM_GPS_CAlLBACK_FUNC callback);
_vm_gps_open_t _vm_gps_open = NULL;

VMINT vm_gps_open(VMUINT period, vm_gps_type_enum type, VM_GPS_CAlLBACK_FUNC callback)
{
    if (NULL == _vm_gps_open)
        _vm_gps_open = (_vm_gps_open_t)vm_get_sym_entry("vm_gps_open");

    if (NULL != _vm_gps_open)
        return _vm_gps_open(period, type, callback);

    return (VMINT )-1;
}
