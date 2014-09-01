#include "vmsys.h"
#include "vmgps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_gps_set_mode_t)(vm_gps_mode_enum mode);
_vm_gps_set_mode_t _vm_gps_set_mode = NULL;

VMINT vm_gps_set_mode(vm_gps_mode_enum mode)
{
    if (NULL == _vm_gps_set_mode)
        _vm_gps_set_mode = (_vm_gps_set_mode_t)vm_get_sym_entry("vm_gps_set_mode");

    if (NULL != _vm_gps_set_mode)
        return _vm_gps_set_mode(mode);

    return (VMINT )-1;
}
