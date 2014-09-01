#include "vmsys.h"
#include "vmusb.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_usb_get_cable_status_t)();
_vm_usb_get_cable_status_t _vm_usb_get_cable_status = NULL;

VMINT vm_usb_get_cable_status()
{
    if (NULL == _vm_usb_get_cable_status)
        _vm_usb_get_cable_status = (_vm_usb_get_cable_status_t)vm_get_sym_entry("vm_usb_get_cable_status");

    if (NULL != _vm_usb_get_cable_status)
        return _vm_usb_get_cable_status();
        
    return (VMINT )-1;
}
