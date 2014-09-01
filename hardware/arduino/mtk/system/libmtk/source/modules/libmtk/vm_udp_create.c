#include "vmsys.h"
#include "vmsock.h"

typedef VMINT (*vm_get_sym_entry_t)(char* symbol);
extern vm_get_sym_entry_t vm_get_sym_entry;

typedef VMINT (*_vm_udp_create_t)(VMINT port, VMINT apn, void (*callback)(VMINT hdl, VMINT event), VMINT loopback);
_vm_udp_create_t _vm_udp_create = NULL;

VMINT vm_udp_create(VMINT port, VMINT apn, void (*callback)(VMINT hdl, VMINT event), VMINT loopback)
{
    if (NULL == _vm_udp_create)
        _vm_udp_create = (_vm_udp_create_t)vm_get_sym_entry("vm_udp_create");

    if (NULL != _vm_udp_create)
        return _vm_udp_create(port, apn, callback, loopback);

    return (VMINT )-1;
}
