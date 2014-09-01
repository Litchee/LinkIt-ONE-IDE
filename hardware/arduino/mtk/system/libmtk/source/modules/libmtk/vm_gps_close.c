#include "vmsys.h"
#include "vmgps.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_gps_close_t)(void);
_vm_gps_close_t _vm_gps_close = NULL;

VMINT vm_gps_close(void)
{
    if (NULL == _vm_gps_close)
        _vm_gps_close = (_vm_gps_close_t)vm_get_sym_entry("vm_gps_close");

    if (NULL != _vm_gps_close)
        return _vm_gps_close();

    return (VMINT )-1;
}
